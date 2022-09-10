using System;
using Class;

namespace Program
{
    internal class Program
    {
        public static void Main()
        {
            // test inheritance class
            Transportation mount = new Car();

            mount.Move();
            Console.WriteLine(mount.Metric);

            // test interface, abstract class inheritance class
            IPolygon shape = new Triangle();

            // cant tessellationcount() 
            Console.WriteLine(shape.GetArea());

            Shape shape1 = new Rectangle();

            // cant getarea()
            Console.WriteLine(shape1.TessellationCount());
            
            return;
        }
    }
}
