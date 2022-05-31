#ifndef MY_VECTOR
#define MY_VECTOR

typedef unsigned int uint32_t;

template <typename T> 
class Vector
{
    private:
        T* allocation = nullptr;
        T* allocationEnd = nullptr;

        size_t allocationUsed = 0;     // used size 
        size_t allocationCapacity = 0; // most of the time bigger than used
        bool deleteAlloc = true;
    public:
        typedef T* iteratorr;
        Vector()
        {
            allocation = new T[1];
            allocationCapacity = 1;
        }
        Vector(size_t size)
        {
            // if(allocation != nullptr)
            // {
            //     delete[] allocation;
            // }

            allocation = new T[size];
            allocationCapacity = size;
            allocationEnd = allocation + size;
        }
        void setDeleteAlloc(bool condition)
        {
            deleteAlloc = condition;
        }
        
        Vector& operator=(Vector &that)
        {
            if(this != &that)
            {
                this->allocation = that.allocation;
                this->allocationCapacity = that.allocationCapacity;
                this->allocationUsed = that.allocationUsed;
                this->allocationEnd = that.allocationEnd;
                this->deleteAlloc = that.deleteAlloc;
                that.setDeleteAlloc(false);
            }
            return *this;
        }

        Vector(const Vector& vector)
        {
            this->allocation = new T[vector.allocationCapacity];
            for(size_t i = 0; i < vector.allocationUsed; i++)
            {
                this->allocation[i] = vector.allocation[i];
            }
            this->allocationCapacity = vector.allocationCapacity;
            this->allocationUsed = vector.allocationUsed;
            this->allocationEnd = vector.allocationEnd;
        }

        void reserve(size_t alloc)
        {
            resize(allocationCapacity + alloc);
        }

        void resize(size_t newSize)
        {
            realloc(newSize);
        }



        ~Vector()
        {
            if(deleteAlloc)
            {
                delete[] allocation;
            }
        }
        iteratorr begin()
        {
            return allocation;
        }

        size_t size()
        {
            return allocationEnd - allocation;
        }
        iteratorr end()
        {
            return allocationEnd;
        }
        size_t getCapacity()
        {
            return allocationCapacity;
        }

        void push_back(T data)
        {
            if(allocationUsed < allocationCapacity)
            {
                allocation[allocationUsed] = data;
                allocationUsed++;
                allocationEnd++;
            }else
            {
                size_t newCapacity = allocationCapacity * (3.0 / 2) + 1;
                realloc(newCapacity);
                push_back(data);
            }
        }

        void realloc(size_t size)
        {

            T* tempPointer = new T[size];
            for(size_t i = 0; i < allocationCapacity; i++)
            {
                tempPointer[i] = allocation[i];
            }
            delete[] allocation;
            allocation = tempPointer;
            allocationCapacity = size;
        }

        T& at(size_t index)
        {
            return allocation[index];
        }

        const T& at(size_t index) const
        {
            return allocation[index];
        }

        T& operator[](size_t index)
        {
            return at(index);
        }

        void erase(iteratorr it)
        {
            for(iteratorr i = it; i < end(); i++)
            {
                if((i + 1) != end())
                {
                    *i = *(i + 1);
                }

            }
        }

};





#endif
