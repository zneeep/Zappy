/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** nullable
*/

#ifndef NULLABLE_HPP_
#define NULLABLE_HPP_

#include <memory>
#include <optional>

namespace my
{
    template <typename TClass>
    class nullable
    {
        public:
            nullable() : value(nullptr) {}
            nullable(std::nullptr_t) : value(nullptr) {}
            nullable(const TClass &value) : value(std::make_shared<TClass>(value)) {}
            nullable(const nullable<TClass> &value) : value(std::move(value.value)) {}

            nullable &operator=(const std::nullptr_t &value)
            {
                this->value = nullptr;
                return (*this);
            }
            nullable &operator=(const TClass &value)
            {
                this->value = std::make_shared<TClass>(value);
                return (*this);
            }
            nullable &operator=(const std::shared_ptr<TClass> &value)
            {
                this->value = value;
                return (*this);
            }

            TClass &operator*()
            {
                if(this->value == nullptr)
                    throw std::logic_error("Attempted to dereference null value");
                return (*this->value);
            }
            const TClass &operator*() const
            {
                if(this->value == nullptr)
                    throw std::logic_error("Attempted to dereference null value");
                return (*this->value);
            }

            TClass* operator->()
            {
                if(this->value == nullptr)
                    throw (std::logic_error("Attempted to dereference null value"));
                return (this->value.get());
            }
            const TClass* operator->() const
            {
                if(this->value == nullptr)
                    throw (std::logic_error("Attempted to dereference null value"));
                return (this->value.get());
            }

            bool operator==(const nullable &other) const
            {
                if (!this->value && !other.value)
                    return (true);
                if (!this->value || !other.value)
                    return (false);
                return *this->value == *other.value;
            }
            bool operator!=(const nullable &other) const
            {
                return !(*this == other);
            }

            explicit operator bool() const
            {
                return (this->value != nullptr);
            }
        private:
            std::shared_ptr<TClass> value;
    };
}

#endif /* !NULLABLE_HPP_ */
