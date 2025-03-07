/* ***************************************************************** 
    MESQUITE -- The Mesh Quality Improvement Toolkit

    Copyright 2006 Sandia National Laboratories.  Developed at the
    University of Wisconsin--Madison under SNL contract number
    624796.  The U.S. Government and the University of Wisconsin
    retain certain rights to this software.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License 
    (lgpl.txt) along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 
    (2006) kraftche@cae.wisc.edu
   
  ***************************************************************** */


/** \file TShapeNB1.hpp
 *  \brief 
 *  \author Jason Kraftcheck 
 */

#ifndef MSQ_T_SHAPE_NB_1_HPP
#define MSQ_T_SHAPE_NB_1_HPP

#include "Mesquite.hpp"
#include "Mesquite_TMetricNonBarrier.hpp"

namespace MESQUITE_NS {


/** \brief Metric sensitive to shape
 *
 * For 2D: \f$ |T - adj(T)^t |^2   =   |T|^2 - 2*det(T) \f$
 *
 * For 3D: \f$ |T|^3 - 3 \sqrt{3} det(T) \f$
 */
class TShapeNB1 : public TMetricNonBarrier
{
  public:
  
  MESQUITE_EXPORT virtual
  std::string get_name() const;

  MESQUITE_EXPORT virtual
  ~TShapeNB1();

  MESQUITE_EXPORT virtual
  bool evaluate( const MsqMatrix<2,2>& T, 
                 double& result, 
                 MsqError& err );

  MESQUITE_EXPORT virtual
  bool evaluate_with_grad( const MsqMatrix<2,2>& T,
                           double& result,
                           MsqMatrix<2,2>& deriv_wrt_T,
                           MsqError& err );

  MESQUITE_EXPORT virtual
  bool evaluate_with_hess( const MsqMatrix<2,2>& T,
                           double& result,
                           MsqMatrix<2,2>& deriv_wrt_T,
                           MsqMatrix<2,2> second_wrt_T[3],
                           MsqError& err );

  MESQUITE_EXPORT virtual
  bool evaluate( const MsqMatrix<3,3>& T, 
                 double& result, 
                 MsqError& err );

  MESQUITE_EXPORT virtual
  bool evaluate_with_grad( const MsqMatrix<3,3>& T,
                           double& result,
                           MsqMatrix<3,3>& deriv_wrt_T,
                           MsqError& err );
  
  MESQUITE_EXPORT virtual
  bool evaluate_with_hess( const MsqMatrix<3,3>& T,
                           double& result,
                           MsqMatrix<3,3>& deriv_wrt_T,
                           MsqMatrix<3,3> second_wrt_T[6],
                           MsqError& err );
};



} // namespace Mesquite

#endif
