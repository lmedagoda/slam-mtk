/*
 *  Copyright (c) 2011 DFKI GmbH
 *  All rights reserved.
 *
 *  Author: Rene Wagner <rene.wagner@dfki.de>
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the DFKI GmbH nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __UKFOM_TRAITS_DOF_HPP__
#define __UKFOM_TRAITS_DOF_HPP__

#include <Eigen/Core>

namespace ukfom {

	template<typename Manifold>
	struct dof
	{
		static const int value = Manifold::DOF;
	};
	
	template<typename scalar, int n>
	struct dof<Eigen::Matrix<scalar, n, 1> >
	{
		static const int value = n;
	};

        template<typename Derived, typename T>
        void setZero(Eigen::MatrixBase<Derived>& cov, const T& type)
        {
                cov.setZero();
        }

        template<typename Scalar>
        void setZero(Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>& cov, const Eigen::Matrix<Scalar, Eigen::Dynamic, 1>& m)
        {
                cov.setZero(m.rows(), m.rows());
        }

        template<typename Scalar, int rows>
        void setZero(Eigen::Matrix<Scalar, rows, Eigen::Dynamic>& cov, const Eigen::Matrix<Scalar, Eigen::Dynamic, 1>& m)
        {
                cov.setZero(rows, m.rows());
        }

        template<typename Scalar, int cols>
        void setZero(Eigen::Matrix<Scalar, Eigen::Dynamic, cols>& cov, const Eigen::Matrix<Scalar, Eigen::Dynamic, 1>& m)
        {
                cov.setZero(m.rows(), cols);
        }

} // namespace ukfom

#endif // __UKFOM_TRAITS_DOF_HPP__
