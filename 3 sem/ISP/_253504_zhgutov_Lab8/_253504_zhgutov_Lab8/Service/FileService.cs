using System;
using System.Collections.Generic;
using System.IO;
using _253504_zhgutov_Lab8.Inferface;
using _253504_zhgutov_Lab8.Models;

namespace _253504_zhgutov_Lab8.Service
{

    class FileService<T> : IFileService<T> where T : Tenant
    {
        public IEnumerable<T> ReadFile(string fileName)
        {
            List<T> tenants = new List<T>(); // Создаем список для хранения данных

            try
            {
                using (BinaryReader reader = new BinaryReader(File.Open(fileName, FileMode.Open)))
                {
                    while (reader.BaseStream.Position != reader.BaseStream.Length)
                    {
                        string name = reader.ReadString();
                        int age = reader.ReadInt32();
                        bool isStudent = reader.ReadBoolean();

                        T tenant = (T)(object)new Tenant { Name = name, Age = age, IsStudent = isStudent };
                        tenants.Add(tenant); // Добавляем данные в список
                    }
                }
            }
            catch (IOException ex)
            {
                Console.WriteLine($"An error occurred while reading the file: {ex.Message}");
            }

            foreach (T tenant in tenants)
            {
                yield return tenant; // Возвращаем данные с помощью yield return
            }
        }

        public void SaveData(IEnumerable<T> data, string fileName)
        {
            try
            {
                using (BinaryWriter writer = new BinaryWriter(File.Open(fileName, FileMode.Create)))
                {
                    foreach (var tenant in data)
                    {
                        writer.Write(tenant.Name);
                        writer.Write(tenant.Age);
                        writer.Write(tenant.IsStudent);
                    }
                }
            }
            catch (IOException ex)
            {
                Console.WriteLine($"An error occurred while writing to the file: {ex.Message}");
            }
        }
    }
}