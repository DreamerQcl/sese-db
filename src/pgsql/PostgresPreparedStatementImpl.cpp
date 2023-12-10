#include <pgsql/PostgresPreparedStatementImpl.h>
#include <catalog/pg_type_d.h>
#include <sstream>

sese::db::impl::PostgresPreparedStatementImpl::PostgresPreparedStatementImpl(const std::string &stmt, uint32_t count, PGconn *conn) noexcept {
    this->stmt = stmt;
    this->count = count;
    this->conn = conn;
    this->paramTypes = (Oid *) malloc(sizeof(Oid) * count);
    memset(this->paramTypes, 0, sizeof(Oid) * count);
    this->paramValues = (const char **) malloc(sizeof(const char *) * count);
    this->strings = new std::string[count];

    std::random_device rand;
    this->result = nullptr;
    if (paramValuesSize == count) {
        createStmt();
    }
}

sese::db::impl::PostgresPreparedStatementImpl::~PostgresPreparedStatementImpl() noexcept {
    if (result) {
        PQclear(result);
        result = nullptr;
    }
    free(paramTypes);
    free(paramValues);
    delete[] this->strings;
}

bool sese::db::impl::PostgresPreparedStatementImpl::setDouble(uint32_t index, double &value) noexcept {
    if (index - 1 >= count) return false;
    this->strings[index - 1] = std::to_string(value);
    this->paramValues[index - 1] = this->strings[index - 1].c_str();
    this->paramTypes[index - 1] = FLOAT8OID;
    this->paramValuesSize++;
//    if (paramValuesSize == count) {
//        createStmt();
//    }
    return true;
}

bool sese::db::impl::PostgresPreparedStatementImpl::setFloat(uint32_t index, float &value) noexcept {
    if (index - 1 >= count) return false;
    this->strings[index - 1] = std::to_string(value);
    this->paramValues[index - 1] = this->strings[index - 1].c_str();
    this->paramTypes[index - 1] = FLOAT4OID;
    this->paramValuesSize++;
//    if (paramValuesSize == count) {
//        createStmt();
//    }
    return true;
}

bool sese::db::impl::PostgresPreparedStatementImpl::setInteger(uint32_t index, int32_t &value) noexcept {
    if (index - 1 >= count) return false;
    this->strings[index - 1] = std::to_string(value);
    this->paramValues[index - 1] = this->strings[index - 1].c_str();
    this->paramTypes[index - 1] = INT4OID;
    this->paramValuesSize++;
//    if (paramValuesSize == count) {
//        createStmt();
//    }
    return true;
}

bool sese::db::impl::PostgresPreparedStatementImpl::setLong(uint32_t index, int64_t &value) noexcept {
    if (index - 1 >= count) return false;
    this->strings[index - 1] = std::to_string(value);
    this->paramValues[index - 1] = this->strings[index - 1].c_str();
    this->paramTypes[index - 1] = INT8OID;
    this->paramValuesSize++;
//    if (paramValuesSize == count) {
//        createStmt();
//    }
    return true;
}

bool sese::db::impl::PostgresPreparedStatementImpl::setText(uint32_t index, const char *value) noexcept {
    if (index - 1 >= count) return false;
    this->paramValues[index - 1] = value;
    this->paramTypes[index - 1] = TEXTOID;
    this->paramValuesSize++;
//    if (paramValuesSize == count) {
//        createStmt();
//    }
    return true;
}

bool sese::db::impl::PostgresPreparedStatementImpl::setNull(uint32_t index) noexcept {
    if (index - 1 >= count) return false;
    this->paramValues[index - 1] = nullptr;
    this->paramTypes[index - 1] = 0;
    this->paramValuesSize++;
//    if (paramValuesSize == count) {
//        createStmt();
//    }
    return true;
}

//创建 stmt 语句
bool sese::db::impl::PostgresPreparedStatementImpl::createStmt() noexcept {
    this->stmtName = "sese_stmt_" + std::to_string(rand());
    const Oid *containerType = paramTypes;

    if (result) {
        PQclear(result);
        result = nullptr;
    }

    result = PQprepare(conn, stmtName.c_str(), stmt.c_str(), count, containerType);
    if (result == nullptr) {
        error = (int) PQstatus(conn);
        return false;
    }

    auto status = PQresultStatus(result);
    if (status != PGRES_COMMAND_OK) {
        error = (int) status;
        return false;
    }

    if (result) {
        PQclear(result);
        result = nullptr;
    }
    return true;
}

sese::db::ResultSet::Ptr sese::db::impl::PostgresPreparedStatementImpl::executeQuery() noexcept {
    if (paramValuesSize >= count) {
        if (!createStmt()) return nullptr;
    }

    result = PQexecPrepared(conn, stmtName.c_str(), count, paramValues, nullptr, nullptr, 0);
    if (result == nullptr) {
        error = (int) PQstatus(conn);
        return nullptr;
    }

    auto status = PQresultStatus(result);

    if (status != PGRES_TUPLES_OK) {
        // fprintf(stderr, "%s\n", PQerrorMessage(conn));
        error = (int) status;
        return nullptr;
    }


    auto rt = std::make_unique<impl::PostgresResultSetImpl>(result);
    error = 0;
    paramValuesSize = 0;
    result = nullptr;
    return rt;
}

int64_t sese::db::impl::PostgresPreparedStatementImpl::executeUpdate() noexcept {
    if (paramValuesSize >= count) {
        if (!createStmt()) return -1;
    }

    result = PQexecPrepared(conn, stmtName.c_str(), count, paramValues, nullptr, nullptr, 0);
    if (result == nullptr) {
        error = (int) PQstatus(conn);
        return -1;
    }

    auto status = PQresultStatus(result);

    if (status != PGRES_COMMAND_OK) {
        // fprintf(stderr, "%s\n", PQerrorMessage(conn));
        error = (int) status;
        return -1;
    }


    auto rt = (int64_t) PQcmdTuples(result);
    PQclear(result);
    paramValuesSize = 0;
    result = nullptr;
    error = 0;
    return rt;
}

int sese::db::impl::PostgresPreparedStatementImpl::getLastError() const noexcept {
    return error;
}

const char *sese::db::impl::PostgresPreparedStatementImpl::getLastErrorMessage() const noexcept {
    if (result) {
        return PQresultErrorMessage(result);
    } else {
        return PQerrorMessage(conn);
    }
}
