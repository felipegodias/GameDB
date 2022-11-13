#ifndef GDB_LIBLET_MEMORY_NEW_ALLOCATOR_HPP
#define GDB_LIBLET_MEMORY_NEW_ALLOCATOR_HPP

#include <cstdlib>
#include <gsl/pointers>

/**
 * \brief 
 * \param _Size 
 * \return 
 */
gsl::owner<void*> operator new(std::size_t size);

/**
 * \brief
 * \param _Block
 */
void operator delete(gsl::owner<void*> ptr) noexcept;

#endif // !GDB_LIBLET_MEMORY_NEW_ALLOCATOR_HPP
