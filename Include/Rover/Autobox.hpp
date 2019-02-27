#ifndef ROVER_AUTOBOX_HPP
#define ROVER_AUTOBOX_HPP

namespace Rover {

  //! Type trait determines what generator is used to represent a given type.
  /*!
    \tparam T The type to represent by a generator.
    \brief If <i>T</i> is itself a generator, then this evaluates to T.
           If <i>T</i> is a pointer or pointer-like class to a generator, then
           this evaluates to a Box<U> where U is the type generated by T.
           Otherwise this evaluates to a Constant<T>.
  */
  template<typename T, typename = void>
  struct autobox {};

  template<typename T>
  using autobox_t = typename autobox<T>::type;

  //! Constructs a generator that conditionally boxes a value.
  /*!
    \param value The value to autobox.
    \return The generator that boxes <i>value</i> or <i>value</i> if no
            boxing is needed.
  */
  template<typename T>
  auto make_autobox(T&& value);
}

#endif
