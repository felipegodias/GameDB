#ifndef GDB_LIBLET_MEMORY_NEW_ALLOCATOR_HPP
#define GDB_LIBLET_MEMORY_NEW_ALLOCATOR_HPP

#include <cstdlib>

/**
 * \brief 
 * \param size 
 * \return 
 */
void* operator new(std::size_t size);

/**
 * \brief
 * \param ptr
 */
void operator delete(void* ptr) noexcept;

/**
 * \brief 
 * \param ptr 
 * \param size 
 */
void operator delete(void* ptr, std::size_t size) noexcept;

#endif // !GDB_LIBLET_MEMORY_NEW_ALLOCATOR_HPP
