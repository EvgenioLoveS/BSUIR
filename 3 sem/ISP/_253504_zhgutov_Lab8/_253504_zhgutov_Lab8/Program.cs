using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using _253504_zhgutov_Lab8.Inferface;
using _253504_zhgutov_Lab8.Service;
using _253504_zhgutov_Lab8.Models;

namespace MyHouseTenantsProject
{
    class Program
    {
        static void Main(string[] args)
        {
            string folderName = "zhgutov_Lab8"; 
            Directory.CreateDirectory(folderName);
            
            Random random = new Random();
            for (int i = 0; i < 10; i++)
            {
                string fileName = Path.Combine(folderName, $"File{i}.{GetRandomExtension(random)}");
                File.Create(fileName).Close();
            }
            
            string[] files = Directory.GetFiles(folderName);
            foreach (var file in files)
            {
                string extension = Path.GetExtension(file);
                Console.WriteLine($"Файл: {Path.GetFileName(file)} имеет расширение {extension}");
            }
            
            List<Tenant> tenants = new List<Tenant>
            {
                new Tenant { Name = "Анна", Age = 25, IsStudent = false },
                new Tenant { Name = "Иван", Age = 30, IsStudent = false },
                new Tenant { Name = "Мария", Age = 22, IsStudent = true },
                new Tenant { Name = "Петр", Age = 28, IsStudent = false },
                new Tenant { Name = "Елена", Age = 23, IsStudent = true },
            };
            
            IFileService<Tenant> fileService = new FileService<Tenant>();
            fileService.SaveData(tenants, "tenants.dat");
            
            File.Move("tenants.dat", "new_tenants.dat");
            
            List<Tenant> newTenants = fileService.ReadFile("new_tenants.dat").ToList();
            
            var sortedTenants = newTenants.OrderBy(t => t, new MyCustomComparer()).ToList();
            
            Console.WriteLine("Исходная коллекция:");
            foreach (var tenant in newTenants)
            {
                Console.WriteLine($"{tenant.Name}, {tenant.Age} лет, студент: {tenant.IsStudent}");
            }

            Console.WriteLine("Отсортированная коллекция по имени:");
            foreach (var tenant in sortedTenants)
            {
                Console.WriteLine($"{tenant.Name}, {tenant.Age} лет, студент: {tenant.IsStudent}");
            }
            
            var sortedByAge = newTenants.OrderBy(t => t.Age).ToList();
            Console.WriteLine("Отсортированная коллекция по возрасту:");
            foreach (var tenant in sortedByAge)
            {
                Console.WriteLine($"{tenant.Name}, {tenant.Age} лет, студент: {tenant.IsStudent}");
            }

        }
        
        static string GetRandomExtension(Random random)
        {
            string[] extensions = { ".txt", ".rtf", ".dat", ".inf" };
            int index = random.Next(extensions.Length);
            return extensions[index];
        }
    }
}