#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void clear_keyboard_buffer(void);


#endif // UTILS_HPP_INCLUDED
