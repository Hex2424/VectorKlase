#ifndef MY_VECTOR
#define MY_VECTOR

typedef unsigned int uint32_t;

template <typename T> 
class Vector
{
    private:
        T* allocation;
        size_t allocationUsed = 0;     // used size 
        size_t allocationCapacity = 0; // most of the time bigger than used
    public:
        typedef T* iterator;
        Vector()
        {
            allocation = new T[0];
        }
        Vector(size_t size)
        {
            allocation = new T[size];
            allocationCapacity = size;
        }
        ~Vector()
        {
            delete[] allocation;
        }
        iterator getBegin()
        {
            return allocation;
        }
        iterator getEnd()
        {
            return allocation + allocationUsed;
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
            }else
            {
                size_t newCapacity = allocationCapacity * (3.0 / 2) + 1;
                T* tempPointer = new T[newCapacity];
                for(size_t i = 0; i < allocationCapacity; i++)
                {
                    tempPointer[i] = allocation[i];
                }
                delete[] allocation;
                allocation = tempPointer;
                allocationCapacity = newCapacity;
                push_back(data);
            }
        }

        T& at(size_t index)
        {
            return allocation[index];
        }

        T& operator[](size_t index)
        {
            return at(index);
        }

        void erase(iterator it)
        {
            for(iterator i = it; i < getEnd(); i++)
            {
                if((i + 1) != getEnd())
                {
                    *i = *(i + 1);
                }

            }
        }

};





#endif
