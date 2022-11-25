#include <sese/db/DriverManager.h>

using sese::db::DatabaseType;
using sese::db::DriverInstance;
using sese::db::DriverManager;
using sese::db::ResultSet;

int main() {
    auto instance = DriverManager::getInstance(DatabaseType::Sqlite, "db_test.db");
    {
        auto result = instance->executeQuery("select user.id, user.name from tb_user user where id = 1;");
        result->next();
        printf("id = %d, name = %s\n", (int) result->getInteger(0), result->getString(1).data());
        auto count = instance->executeUpdate(R"(update tb_user set name = "kaoru" where id = 1;)");
        printf("update rows: %d\n", (int) count);
    }

    {
        int64_t value = 2;
        auto stmt = instance->createStatement("update tb_user set name = ? where id = ?;");
        stmt->setText(1, "mike");
        stmt->setInteger(2, value);
        auto count = stmt->executeUpdate();
        printf("stmt update rows: %d\n", (int) count);
    }

    {
        auto stmt = instance->createStatement("select * from tb_user;");
        auto result = stmt->executeQuery();
        while (result->next()) {
            printf("stmt result: id = %d, name = %s\n", (int) result->getInteger(0), result->getString(1).data());
        }
    }

    return 0;
}