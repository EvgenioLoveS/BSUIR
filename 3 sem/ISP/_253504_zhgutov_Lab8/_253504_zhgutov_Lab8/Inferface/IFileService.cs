using System;
using System.Collections.Generic;

namespace _253504_zhgutov_Lab8.Inferface
{
    public interface IFileService<T>
    {
        IEnumerable<T> ReadFile(string fileName);
        void SaveData(IEnumerable<T> data, string fileName);
    }
}