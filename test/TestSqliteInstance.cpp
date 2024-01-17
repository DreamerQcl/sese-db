#include <sese/db/DriverManager.h>
#include <sese/util/Initializer.h>
#include <gtest/gtest.h>
#include <cinttypes>

using sese::db::DatabaseType;
using sese::db::DriverInstance;
using sese::db::DriverManager;
using sese::db::ResultSet;

TEST(TestSqliteDriverInstance, TestError) {
    auto instance = DriverManager::getInstance(DatabaseType::Sqlite, PATH_TO_DB);
    ASSERT_NE(nullptr, instance);
    ASSERT_EQ(0, instance->getLastError());

    auto resultError = instance->executeQuery("select * from tb_query_error where id = 1;");
    ASSERT_EQ(nullptr, resultError);

    printf("errorMsg: %s\n", instance->getLastErrorMessage());

    //stmtError
    auto resultStmtError = instance->createStatement("select * from tb_stmt_query_error where id = 1;");
    ASSERT_EQ(nullptr, resultStmtError);

    printf("errorMsg: %s\n", instance->getLastErrorMessage());
}

// query
TEST(TestSqliteDriverInstance, TestQueryData) {
    auto instance = DriverManager::getInstance(DatabaseType::Sqlite, PATH_TO_DB);
    ASSERT_NE(nullptr, instance);
    ASSERT_EQ(0, instance->getLastError());

    auto result = instance->executeQuery("select * from tb_query where id = 1;");
    ASSERT_NE(nullptr, result);
    while (result->next()) {
        printf("id = %" PRId32 ", name = %s Columns = %zu\n", (int) result->getInteger(0), result->getString(1).data(), result->getColumns());
    }

    result->reset();

    while (result->next()) {
        printf("id = %" PRId32 ", name = %s Columns = %zu\n", (int) result->getInteger(0), result->getString(1).data(), result->getColumns());
    }
}

// update
TEST(TestSqliteDriverInstance, TestUpdateData) {
    auto instance = DriverManager::getInstance(DatabaseType::Sqlite, PATH_TO_DB);
    ASSERT_NE(nullptr, instance);
    ASSERT_EQ(0, instance->getLastError());

    auto result = instance->executeQuery("select * from tb_update where id = 1;");
    ASSERT_NE(nullptr, result);
    while (result->next()) {
        printf("result id = %" PRId32 ", name = %s\n", (int) result->getInteger(0), result->getString(1).data());
    }

    auto count = instance->executeUpdate(R"(update tb_update set name = "mike" where id = 1;)");
    ASSERT_NE(-1, count);

    auto result1 = instance->executeQuery("select * from tb_update where id = 1;");
    ASSERT_NE(nullptr, result1);
    while (result1->next()) {
        printf("result1 id = %" PRId32 ", name = %s\n", (int) result1->getInteger(0), result1->getString(1).data());
    }
}

// delete
TEST(TestSqliteDriverInstance, TestDeleteData) {
    auto instance = DriverManager::getInstance(DatabaseType::Sqlite, PATH_TO_DB);
    ASSERT_NE(nullptr, instance);
    ASSERT_EQ(0, instance->getLastError());

    auto result = instance->executeQuery("select * from tb_delete;");
    ASSERT_NE(nullptr, result);
    while (result->next()) {
        printf("result id = %" PRId32 ", name = %s\n", (int) result->getInteger(0), result->getString(1).data());
    }

    auto count = instance->executeUpdate("delete from tb_delete where id = 1;");
    ASSERT_NE(-1, count);

    auto result1 = instance->executeQuery("select * from tb_delete;");
    ASSERT_NE(nullptr, result1);
    while (result1->next()) {
        printf("result1 id = %" PRId32 ", name = %s\n", (int) result1->getInteger(0), result1->getString(1).data());
    }
}

// insert
TEST(TestSqliteDriverInstance, TestInsertData) {
    auto instance = DriverManager::getInstance(DatabaseType::Sqlite, PATH_TO_DB);
    ASSERT_NE(nullptr, instance);
    ASSERT_EQ(0, instance->getLastError());

    auto result = instance->executeQuery("select * from tb_insert;");
    ASSERT_NE(nullptr, result);
    while (result->next()) {
        printf("result id = %" PRId32 ", name = %s\n", (int) result->getInteger(0), result->getString(1).data());
    }

    auto count = instance->executeUpdate("insert into tb_insert (id, name) values (3, 'mike');");
    ASSERT_NE(-1, count);

    auto result1 = instance->executeQuery("select * from tb_insert;");
    ASSERT_NE(nullptr, result1);
    while (result1->next()) {
        printf("result1 id = %" PRId32 ", name = %s\n", (int) result1->getInteger(0), result1->getString(1).data());
    }
}
