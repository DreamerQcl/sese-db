#include <sese/db/impl/SqliteStmtResultSetImpl.h>

using namespace sese::db;

void impl::SqliteStmtResultSetImpl::reset() noexcept {
    sqlite3_reset(stmt);
}

bool impl::SqliteStmtResultSetImpl::next() noexcept {
    return sqlite3_step(stmt) == SQLITE_ROW;
}

//const char *impl::SqliteStmtResultSetImpl::getColumnByIndex(size_t index) const noexcept {
//    return (const char *) sqlite3_column_text(stmt, (int) index);
//}

size_t impl::SqliteStmtResultSetImpl::getColumns() const noexcept {
    return sqlite3_column_count(stmt);
}

impl::SqliteStmtResultSetImpl::SqliteStmtResultSetImpl(sqlite3_stmt *stmt) noexcept {
    this->stmt = stmt;
}

int64_t impl::SqliteStmtResultSetImpl::getInteger(size_t index) const noexcept {
    auto p = (const char *) sqlite3_column_text(stmt, (int) index);
    char *end;
    return std::strtoll(p, &end, 10);
}

std::string_view impl::SqliteStmtResultSetImpl::getString(size_t index) const noexcept {
    auto p = (const char *) sqlite3_column_text(stmt, (int) index);
    return {p};
}

double impl::SqliteStmtResultSetImpl::getDouble(size_t index) const noexcept {
    auto p = (const char *) sqlite3_column_text(stmt, (int) index);
    char *end;
    return std::strtod(p, &end);
}

float impl::SqliteStmtResultSetImpl::getFloat(size_t index) const noexcept {
    auto p = (const char *) sqlite3_column_text(stmt, (int) index);
    char *end;
    return std::strtof(p, &end);
}
