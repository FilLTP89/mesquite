/* ***************************************************************** 
    MESQUITE -- The Mesh Quality Improvement Toolkit

    Copyright 2007 Sandia National Laboratories.  Developed at the
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

    (2009) kraftche@cae.wisc.edu    

  ***************************************************************** */


/** \file LambdaConstant.hpp
 *  \brief 
 *  \author Jason Kraftcheck 
 */

#ifndef MSQ_LAMBDA_CONSTANT_HPP
#define MSQ_LAMBDA_CONSTANT_HPP

#include "Mesquite.hpp"
#include "Mesquite_TargetCalculator.hpp"

namespace MESQUITE_NS {

/**\brief Scale a target matrix 
 *
 * Use the specified target calculator to determine the shape and orientation
 * portions of the target matrix, but make the size component (lambda)
 * a constant.
 */
class LambdaConstant : public TargetCalculator
{
public:
  /**
   *\param lambda Target size.
   *\param target Target calcualtor from which to obtain
   *               a target that will be scaled by lambda.
   */
  LambdaConstant( double lambda, TargetCalculator* target );
  
  ~LambdaConstant();
  
  bool get_3D_target( PatchData& pd, 
                      size_t element,
                      Sample sample,
                      MsqMatrix<3,3>& W_out,
                      MsqError& err );

  bool get_2D_target( PatchData& pd, 
                      size_t element,
                      Sample sample,
                      MsqMatrix<2,2>& W_out,
                      MsqError& err );

  bool get_surface_target( PatchData& pd, 
                      size_t element,
                      Sample sample,
                      MsqMatrix<3,2>& W_out,
                      MsqError& err );
  
  bool have_surface_orient() const
    { return mTarget->have_surface_orient(); }

private:
  double mLambda;
  TargetCalculator* mTarget;
};


} // namespace MESQUITE_NS

#endif
