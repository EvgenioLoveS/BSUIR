using System.Reflection;

namespace _253504_zhgutov_Lab10
{
    public class Program
    {
        static void Main(string[] args)
        {
            List<Employee> employees = new List<Employee>
            {
                new Employee(101, "John Smith", false),
                new Employee(102, "Jane Doe", false),
                new Employee(103, "Bob Johnson", true),
                new Employee(104, "Alice Brown", false),
                new Employee(105, "David Lee", true),
                new Employee(106, "Sarah Wilson", false)
            };

            string fileName = "file.json";

            string assemblyPath = "D:\\253505\\ИСП\\_253504_zhgutov_Lab10\\Services\\bin\\Debug\\net7.0\\Services.dll";    
            
            Assembly asm = Assembly.LoadFrom(assemblyPath);
            Type? type = asm.GetType("Services.FileService`1");
            var genType = type.MakeGenericType(new[] { typeof(Employee) });
            var instance = Activator.CreateInstance(genType);
            
            MethodInfo saveMethod = genType.GetMethod("SaveData", BindingFlags.Instance | BindingFlags.Public);
            saveMethod.Invoke(instance, new object[] { employees, fileName });

            MethodInfo readMethod = genType.GetMethod("ReadFile", BindingFlags.Instance | BindingFlags.Public);
            var list = (IEnumerable<Employee>)readMethod.Invoke(instance, new object[] { fileName });
            
            foreach (var employee in list)
            {
                Console.WriteLine($"Employee ID: {employee.Id}, Employee Name: {employee.Name}, Is Deleted: {employee.IsDeleted}");
            }
        }
    }
}