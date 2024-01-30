using System;
using System.Collections.Generic;
using _253504_zhgutov_Lab8.Models;

namespace _253504_zhgutov_Lab8.Service
{
    class MyCustomComparer : IComparer<Tenant>
    {
        public int Compare(Tenant x, Tenant y)
        {
            return string.Compare(x.Name, y.Name, StringComparison.OrdinalIgnoreCase);
        }
    }
}