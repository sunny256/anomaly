////////////////////////////////////////////////////////////////////////////////
// anomaly - Anomalous data detection
//
// Copyright 2013, Göteborg Bit Factory.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <vector>
//#include <stdlib.h>
//#include <math.h>

////////////////////////////////////////////////////////////////////////////////
int algorithm_sigma ()
{
/*
  // Process arguments from command line.
  std::vector <double> data;
  for (int i = 1; i < argc; i++)
    data.push_back (strtod (argv[i], NULL));

  double sigma = 0.0;
  double mean = 0.0;

  int n = data.size ();
  if (n > 1)
  {
    // Calculate mean, standard deviation.
    double sum = 0.0;
    double sum_squares = 0.0;
    std::vector <double>::iterator i;
    for (i = data.begin (); i != data.end (); ++i)
    {
      sum += *i;
      sum_squares += (*i) * (*i);
    }

    sigma = sqrt (((n * sum_squares) - (sum * sum)) / (n * (n - 1)));
    mean = sum / n;
  }
  else if (n > 0)
  {
    mean = data[0];
  }

  std::cout << mean  << "\n"
            << sigma << "\n";
*/
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
