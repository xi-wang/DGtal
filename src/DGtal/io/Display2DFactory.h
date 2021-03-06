/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file   Display2DFactory.h
 * @author Martial Tola <http://liris.cnrs.fr/martial.tola/>
 * @date   mercredi 28 septembre 2011
 * 
 * @brief
 *
 * Header file for module Display2DFactory
 *
 * This file is part of the DGtal library.
 */

#if defined(Display2DFactory_RECURSES)
#error Recursive header files inclusion detected in Display2DFactory.h
#else // defined(Display2DFactory_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Display2DFactory_RECURSES

#if !defined Display2DFactory_h
/** Prevents repeated inclusion of headers. */
#define Display2DFactory_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions

#include "DGtal/base/Common.h"

#include "DGtal/math/AngleLinearMinimizer.h"
#include "DGtal/geometry/curves/representation/ArithmeticalDSS.h"
#include "DGtal/shapes/fromPoints/CircleFrom2Points.h"
#include "DGtal/shapes/fromPoints/CircleFrom3Points.h"
#include "DGtal/kernel/sets/DigitalSetBySTLSet.h"
#include "DGtal/kernel/sets/DigitalSetBySTLVector.h"
#include "DGtal/geometry/curves/representation/FP.h"
#include "DGtal/geometry/curves/representation/FreemanChain.h"
#include "DGtal/geometry/curves/representation/GeometricalDSS.h"
#include "DGtal/geometry/curves/representation/GeometricalDCA.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include "DGtal/images/ImageContainerByHashTree.h"
#include "DGtal/images/ImageContainerBySTLVector.h"
#include "DGtal/topology/KhalimskySpaceND.h"
#include "DGtal/topology/Object.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/geometry/tools/Preimage2D.h"
#include "DGtal/shapes/fromPoints/StraightLineFrom2Points.h"

#include "DGtal/io/boards/Board2D.h"

//////////////////////////////////////////////////////////////////////////////


//namespace DGtal
//{

/////////////////////////////////////////////////////////////////////////////
// struct Display2DFactory
/**
 * Description of struct 'Display2DFactory' <p>
 * \brief Factory for Display2D:
 */
//  namespace Display2DFactory
// {

    
// AngleLinearMinimizer
void draw( DGtal::Board2D & board, const DGtal::AngleLinearMinimizer & );
// AngleLinearMinimizer
    
    
// ArithmeticalDSS
template <typename TIterator, typename TInteger, int connectivity>
  void drawAsBoundingBox( DGtal::Board2D & aBoard, 
			  const DGtal::ArithmeticalDSS<TIterator,TInteger,connectivity> & );

template <typename TIterator, typename TInteger, int connectivity>
  void drawAsDigitalPoints( DGtal::Board2D & aBoard, 
			    const DGtal::ArithmeticalDSS<TIterator,TInteger,connectivity> & );

template <typename TIterator, typename TInteger, int connectivity>
  void draw( DGtal::Board2D & board, const DGtal::ArithmeticalDSS<TIterator,TInteger,connectivity> & );
// ArithmeticalDSS
    
    
// CircleFrom2Points
template <typename TPoint>
void draw(Board2D & aBoard, const DGtal::CircleFrom2Points<TPoint> & );
// CircleFrom2Points


// CircleFrom3Points
template <typename Point>
void drawArc(Board2D & aBoard, const DGtal::CircleFrom3Points<Point> &, const Point &, const Point &, bool anOrientation = true);
    
template <typename Point>
void drawSector(Board2D & aBoard, const DGtal::CircleFrom3Points<Point> &, const Point &, const Point &, bool anOrientation = true);
    
template <typename Point>
void drawAnnulus(Board2D & aBoard, const DGtal::CircleFrom3Points<Point> &, const Point &, const Point &, const double& w = 1.0, bool anOrientation = true);
    
template <typename Point>
void draw(Board2D & aBoard, const DGtal::CircleFrom3Points<Point> &, const Point &, const Point &, bool anOrientation = true);
    
template <typename TPoint>
void draw(Board2D & aBoard, const DGtal::CircleFrom3Points<TPoint> & );
// CircleFrom3Points
    
    
// DigitalSetBySTLSet
template<typename Domain>
void draw( DGtal::Board2D & board, const DGtal::DigitalSetBySTLSet<Domain> & );
// DigitalSetBySTLSet
    
    
// DigitalSetBySTLVector
template<typename Domain>
void draw( DGtal::Board2D & board, const DGtal::DigitalSetBySTLVector<Domain> & );
// DigitalSetBySTLVector
    
    
// FP
template <typename TIterator, typename TInteger, int connectivity>
  void drawAsPolygon( DGtal::Board2D & aBoard, const DGtal::FP<TIterator,TInteger,connectivity> & );

template <typename TIterator, typename TInteger, int connectivity>
  void draw( DGtal::Board2D & board, const DGtal::FP<TIterator,TInteger,connectivity> & );
// FP
    
    
// FreemanChain
template <typename TInteger>
void drawAsGrid( DGtal::Board2D & aBoard, const DGtal::FreemanChain<TInteger> & );
    
template <typename TInteger>
void drawAsInterGrid( DGtal::Board2D & aBoard, const DGtal::FreemanChain<TInteger> & );
    
template <typename TInteger>
void draw( DGtal::Board2D & aBoard, const DGtal::FreemanChain<TInteger> & );
// FreemanChain
    
    
// GeometricalDSS
template <typename TConstIterator>
void draw(DGtal::Board2D & aBoard, const DGtal::GeometricalDSS<TConstIterator> & );
// GeometricalDSS
    
// GeometricalDCA
template <typename TConstIterator>
void draw(DGtal::Board2D & aBoard, const DGtal::GeometricalDCA<TConstIterator> & );
// GeometricalDCA

    
// GridCurve
// we use setStyle because of inner classes
// GridCurve
    
    
// HyperRectDomain
template<typename TSpace>
void drawAsGrid( DGtal::Board2D & aboard, const DGtal::HyperRectDomain<TSpace> & );

template<typename TSpace>
void drawAsPaving( DGtal::Board2D & aboard, const DGtal::HyperRectDomain<TSpace> & );

template<typename TSpace>
void draw( DGtal::Board2D & board, const DGtal::HyperRectDomain<TSpace> & );
// HyperRectDomain
    
    
// ImageContainerByHashTree
template <typename C, typename Domain, typename Value, typename HashKey>
void drawImageRecursive( DGtal::Board2D & aBoard, 
                         const DGtal::ImageContainerByHashTree<Domain, Value, HashKey> & i,
                         HashKey key,
                         const double p[2],
                         const double len,
                         LibBoard::Board & board,
                         const C& cmap );

template <typename C, typename Domain, typename Value, typename HashKey>
void drawImage( Board2D & board,
                const DGtal::ImageContainerByHashTree<Domain, Value, HashKey> &, 
                const Value &, const Value & );
// ImageContainerByHashTree


// ImageContainerBySTLVector
template <typename Colormap, typename D, typename V>
  void drawImage( DGtal::Board2D & board, const DGtal::ImageContainerBySTLVector<D, V> &, const V &, const V & );
// ImageContainerBySTLVector
    
    
// KhalimskyCell
template < Dimension dim, typename TInteger >
  void draw( DGtal::Board2D & board, const DGtal::KhalimskyCell<dim, TInteger> & );
// KhalimskyCell
    
    
// Object
template <typename TDigitalTopology, typename TDigitalSet>
  void drawWithAdjacencies( DGtal::Board2D & aBoard, const DGtal::Object<TDigitalTopology, TDigitalSet> & );

template <typename TDigitalTopology, typename TDigitalSet>
  void draw( DGtal::Board2D & board, const DGtal::Object<TDigitalTopology, TDigitalSet> & );
// Object
    
    
// PointVector
template<Dimension dim, typename TComponent>
  void drawAsPaving( DGtal::Board2D & board, const DGtal::PointVector<dim,TComponent> & );

template<Dimension dim, typename TComponent>
  void drawAsGrid( DGtal::Board2D & board, const DGtal::PointVector<dim,TComponent> & );

template<Dimension dim, typename TComponent>
  void draw( DGtal::Board2D & board, const DGtal::PointVector<dim,TComponent> & );

template<Dimension dim, typename TComponent>
  void draw( DGtal::Board2D & board, 
	     const DGtal::PointVector<dim,TComponent> &, 
	     const DGtal::PointVector<dim,TComponent> & );
// PointVector
    
    
// Preimage2D
template <typename Shape>
void draw( DGtal::Board2D & aBoard, const DGtal::Preimage2D<Shape> & );
// Preimage2D
    
    
// SignedKhalimskyCell
template < Dimension dim, typename TInteger >
  void draw( DGtal::Board2D & board, const DGtal::SignedKhalimskyCell<dim, TInteger> & );
// SignedKhalimskyCell
    
    
// StraightLineFrom2Points
template <typename TPoint>
void draw(Board2D & aBoard, const DGtal::StraightLineFrom2Points<TPoint> & );
// StraightLineFrom2Points
  
    
//
    
    
void draw( DGtal::Board2D & board, const DGtal::CustomStyle & );
void draw( DGtal::Board2D & board, const DGtal::SetMode & );

    
//  }; // end of struct Display2DFactory

//} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions/methods 
#include "DGtal/io/Display2DFactory.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Display2DFactory_h

#undef Display2DFactory_RECURSES
#endif // else defined(Display2DFactory_RECURSES)
