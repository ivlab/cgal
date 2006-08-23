// Copyright (c) 2005-2006  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Partially supported by the IST Programme of the EU as a Shared-cost
// RTD (FET Open) Project under Contract No  IST-2000-26473 
// (ECG - Effective Computational Geometry for Curves and Surfaces) 
// and a STREP (FET Open) Project under Contract No  IST-006413 
// (ACS -- Algorithms for Complex Shapes)
//
// $URL: $
// $Id: $
//
// Author(s) : Monique Teillaud <Monique.Teillaud@sophia.inria.fr>
//             Sylvain Pion     <Sylvain.Pion@sophia.inria.fr>
//             Pedro Machado    <tashimir@gmail.com>

#include <CGAL/Random.h>

template <class AK>
void _test_constuctor(AK ak)
{
  CGAL::Random generatorOfgenerator;
  int random_seed = generatorOfgenerator.get_int(0, 123456);
  std::cout << "random_seed = " << random_seed << std::endl;
  CGAL::Random theRandom(random_seed);
  int random_max = 127;
  int random_min = -127;
  typename AK::Construct_polynomial_for_spheres_2_3 theConstruct_2_3 =
    ak.construct_polynomial_for_spheres_2_3_object();
  typename AK::Construct_polynomial_1_3 theConstruct_1_3 =
    ak.construct_polynomial_1_3_object();
  typename AK::Construct_polynomials_for_line_3 theConstruct_line_3 =
    ak.construct_polynomials_for_line_3_object();
  
  for(int i = 0; i < 20 ; i++){
    int x = theRandom.get_int(random_min,random_max);
    int y = theRandom.get_int(random_min,random_max);
    int z = theRandom.get_int(random_min,random_max); 
    int r_sq = theRandom.get_int(random_min,random_max);
    int a = theRandom.get_int(random_min,random_max);
    int b = theRandom.get_int(random_min,random_max);
    int c = theRandom.get_int(random_min,random_max);
    int d = theRandom.get_int(random_min,random_max);
    int a1 = theRandom.get_int(random_min,random_max);
    int b1 = theRandom.get_int(random_min,random_max);
    int a2 = theRandom.get_int(random_min,random_max);
    int b2 = theRandom.get_int(random_min,random_max);
    int a3 = theRandom.get_int(random_min,random_max);
    int b3 = theRandom.get_int(random_min,random_max);
    typename AK::Polynomial_for_spheres_2_3 p_2_3 = theConstruct_2_3(x, y, z, r_sq);
    typename AK::Polynomial_1_3 p_1_3 = theConstruct_1_3(a, b, c, d);
    typename AK::Polynomials_for_line_3 p_line_3 = theConstruct_line_3(a1, b1, a2, b2, a3, b3);
    assert(p_2_3.a() == x);
    assert(p_2_3.b() == y);
    assert(p_2_3.c() == z);
    assert(p_2_3.r_sq() == r_sq);
    assert(p_1_3.a() == a);
    assert(p_1_3.b() == b);
    assert(p_1_3.c() == c);
    assert(p_1_3.d() == d);
    assert(p_line_3.a1() == a1);
    assert(p_line_3.b1() == b1);
    assert(p_line_3.a2() == a2);
    assert(p_line_3.b2() == b2);
    assert(p_line_3.a3() == a3);
    assert(p_line_3.b3() == b3);
  }
  
}
