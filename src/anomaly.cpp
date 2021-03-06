////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013 - 2017, Göteborg Bit Factory.
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

#include <cmake.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <Detector.h>
#include <shared.h>

////////////////////////////////////////////////////////////////////////////////
static int usage ()
{
  std::cout << "\n"
               "Usage: anomaly [options]\n"
               "\n"
               "Options:\n"
               "  -h|--help               Show this message\n"
               "  -v|--version            Show anomaly version & copyright\n"
               "  -d|--details            Show internal details\n"
               "\n"
               "Detection: Threshold\n"
               "  -t|--threshold          Threshold algorithm\n"
               "     --min N              Lower threshold\n"
               "     --max N              Upper threshold\n"
               "\n"
               "Detection: Standard Deviation\n"
               "  -s|--stddev             Standard Deviation algorithm (default)\n"
               "  -n|--sample N           Sample size (default: 10)\n"
               "  -c|--coefficient N      Coefficient for --stddev (default: 1.0)\n"
               "\n"
               "Responses:\n"
               "  -q|--quiet              Suppresses anomaly description output\n"
               "  -e|--execute PROGRAM    Runs program\n"
               "  -p|--pid PID            Sends USR1 signal to pid\n"
               "\n";

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
static int version ()
{
  std::cout << "\n"
            << PACKAGE_STRING
            << " built for "
            << osName ()
            << "\n"
               "Copyright (C) 2013 - 2017 Göteborg Bit Factory\n"
               "\n"
               "Anomaly may be copied only under the terms of the MIT "
               "license, which may be found in the source kit.\n"
               "\n"
               "Documentation for anomaly can be found using 'man anomaly' "
               "or at http://tasktools.org/projects/anomaly.html\n"
               "\n";

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
int main (int argc, char** argv)
{
  try
  {
    Detector detector;

    // Process command line arguments.
    for (int i = 1; i < argc; ++i)
    {
      if (!strcmp (argv[i], "-h") || !strcmp (argv[i], "--help"))
        return usage ();

      else if (!strcmp (argv[i], "-v") || !strcmp (argv[i], "--version"))
        return version ();

      else if (!strcmp (argv[i], "-d") || !strcmp (argv[i], "--details"))
        detector.debug ();

      else if (!strcmp (argv[i], "-t") || !strcmp (argv[i], "--threshold"))
        detector.algorithm ("threshold");

      else if (!strcmp (argv[i], "--max"))
        detector.max (strtod (argv[++i], nullptr));

      else if (!strcmp (argv[i], "--min"))
        detector.min (strtod (argv[++i], nullptr));

      else if (!strcmp (argv[i], "-s") || !strcmp (argv[i], "--stddev"))
        detector.algorithm ("stddev");

      else if (!strcmp (argv[i], "-n") || !strcmp (argv[i], "--sample"))
        detector.sample (strtol (argv[++i], nullptr, 10));

      else if (!strcmp (argv[i], "-c") || !strcmp (argv[i], "--coefficient"))
        detector.coefficient (strtod (argv[++i], nullptr));

      else if (!strcmp (argv[i], "-q") || !strcmp (argv[i], "--quiet"))
        detector.quiet ();

      else if (!strcmp (argv[i], "-p") || !strcmp (argv[i], "--pid"))
        detector.pid (strtol (argv[++i], nullptr, 10));

      else if (!strcmp (argv[i], "-e") || !strcmp (argv[i], "--execute"))
        detector.execute (argv[++i]);

      else
        throw std::string ("Unrecognized argument '") + argv[i] + "'.";
    }

    // Dispatch to selected algorithm.
    detector.run ();
  }

  catch (const std::string& error)
  {
    std::cout << error << "\n";
    return -1;
  }

  catch (...)
  {
    std::cout << "Unknown error\n";
    return -2;
  }

  return 0;
}

////////////////////////////////////////////////////////////////////////////////

