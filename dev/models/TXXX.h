#pragma once

/**
 * @file XXX.h
 * @author AUTHOR (\c EMAIL )
 * INSTITUTION
 *
 * @date 2000/??/??
 *
 * Header file for module XXX.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(XXX_RECURSES)
#error Recursive header files inclusion detected in XXX.h
#else // defined(XXX_RECURSES)
/** Prevents recursive inclusion of headers. */
#define XXX_RECURSES

#if !defined XXX_h
/** Prevents repeated inclusion of headers. */
#define XXX_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "YYY/base/Common.h"
//////////////////////////////////////////////////////////////////////////////

namespace YYY
{

/////////////////////////////////////////////////////////////////////////////
// class XXX
/**
 * Description of class 'XXX' <p>
 * Aim:
 */
class XXX
{
    // ----------------------- Standard services ------------------------------
public:

    /**
     * Destructor.
     */
    ~XXX();

    // ----------------------- Interface --------------------------------------
public:

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay ( std::ostream & out ) const;

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    // ------------------------- Protected Datas ------------------------------
private:
    // ------------------------- Private Datas --------------------------------
private:

    // ------------------------- Hidden services ------------------------------
protected:

    /**
     * Constructor.
     * Forbidden by default (protected to avoid g++ warnings).
     */
    XXX();

private:

    /**
     * Copy constructor.
     * @param other the object to clone.
     * Forbidden by default.
     */
    XXX ( const XXX & other );

    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     * Forbidden by default.
     */
    XXX & operator= ( const XXX & other );

    // ------------------------- Internals ------------------------------------
private:

}; // end of class XXX


/**
 * Overloads 'operator<<' for displaying objects of class 'XXX'.
 * @param out the output stream where the object is written.
 * @param object the object of class 'XXX' to write.
 * @return the output stream after the writing.
 */
inline
std::ostream&
operator<< ( std::ostream & out, const XXX & object );
 {
   object.selfDisplay( out );
   return out;
 }

} // namespace YYY


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "YYY/ZZZ/XXX.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined XXX_h

#undef XXX_RECURSES
#endif // else defined(XXX_RECURSES)