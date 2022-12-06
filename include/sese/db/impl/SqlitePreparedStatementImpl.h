#pragma once
#include <sese/db/PreparedStatement.h>
#include <sese/db/impl/SqliteStmtResultSetImpl.h>

namespace sese::db::impl {

    class SESE_DB_API SqlitePreparedStatementImpl : public PreparedStatement {
    public:
        explicit SqlitePreparedStatementImpl(sqlite3_stmt *stmt) noexcept;
        ~SqlitePreparedStatementImpl() noexcept override;

        ResultSet::Ptr executeQuery() noexcept override;
        int64_t executeUpdate() noexcept override;
        bool setDouble(uint32_t index, double &value) noexcept override;
        bool setFloat(uint32_t index, float &value) noexcept override;
        bool setLong(uint32_t index, int64_t &value) noexcept override;
        bool setInteger(uint32_t index, int32_t &value) noexcept override;
        bool setText(uint32_t index, const char *value) noexcept override;
        bool setNull(uint32_t index) noexcept override;

    protected:
        sqlite3_stmt *stmt;
    };

}// namespace sese::db::impl