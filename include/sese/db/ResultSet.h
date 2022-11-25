#pragma once
#include <sese/db/Config.h>
#include <string>

namespace sese::db {

    class SESE_DB_API ResultSet {
    public:
        using Ptr = std::unique_ptr<ResultSet>;

        virtual ~ResultSet() noexcept = default;
        virtual void reset() noexcept = 0;
        [[nodiscard]] virtual bool next() noexcept = 0;
        // [[nodiscard]] virtual const char *getColumnByIndex(size_t index) const noexcept = 0;
        [[nodiscard]] virtual size_t getColumns() const noexcept = 0;

        [[nodiscard]] virtual int32_t getInteger(size_t index) const noexcept = 0;
        [[nodiscard]] virtual int64_t getLong(size_t index) const noexcept = 0;
        [[nodiscard]] virtual std::string_view getString(size_t index) const noexcept = 0;
        [[nodiscard]] virtual double getDouble(size_t index) const noexcept = 0;
        [[nodiscard]] virtual float getFloat(size_t index) const noexcept = 0;
    };
}