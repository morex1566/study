namespace Class
{

    // getter setter property를 사용한 기본 클래스 구현
    // Q : getter setter 보다 더 좋은 디자인의 캡슐화 표현?
    /*
     * A : getter setter 디자인이 나쁜게 아니다.
     * 모든 private field에 getter setter를 관습적으로 작성하는게 나쁜것이다.
     * 이것은 객체간의 결합도를 높인다.
     * 가급적 getter setter로 수정하지 말고 그 객체에게 권한을 넘기는 것이 좋은 방법이다.
     */
    class MyClass
    {
        public MyClass()
        {
            myField = 0.0f;
        }
        ~MyClass()
        {

        }

        public float Field { get { return myField; } set { myField = value; } }
        private float myField;
    }

    // 일반 클래스의 상속
    // is - a 관계일 경우에는 상속, has - a 관계일 경우에는 구성으로 구현
    // c#의 경우에는 virtual 소멸자를 사용하지 않음.
    // 자식은 부모 생성자를 호출해야 함. use base()
    class Transportation
    {
        public Transportation()
        {
            speed = 1.0f;
            metric = 0.0f;
        }
        ~Transportation()
        {

        }

        public virtual void Move()
        {
            metric += speed;
        }

        public float Speed { get { return speed; } set { speed = value; } }
        public float Metric { get { return metric; }}

        protected float speed;
        protected float metric;
    }

    class Car : Transportation
    {
        public Car()
            : base()
        {
            speed = 2.0f;
        }
        ~Car()
        {

        }

        public override void Move()
        {
            metric += speed * 2;
        }
    }

    /*
     * 인터페이스는 서로 관련하지 않는 객체끼리 계약을 구현할 때,
     * 추상클래스는 서로 관련된 객체의 같이 사용하는 기능을 각자 확장 시킬 때,
     * 인터페이스는 예외적으로 다중상속을 지원한다.
     * c#에서는 abstract로 가상함수 표현, not virtual or = 0
     */
    interface IPolygon
    {
        float GetArea();
    }
    public abstract class Shape
    {
        public Shape()
        {
            height = 1.0f;
            length = 1.0f;
        }
        ~Shape()
        {

        }

        public abstract int TessellationCount();

        protected float height;
        protected float length;
    }

    public class Triangle : Shape, IPolygon
    {
        public Triangle()
            : base()
        {
          
        }
        ~Triangle()
        {

        }

        float IPolygon.GetArea()
        {
            return height * length / 2;
        }
        public override int TessellationCount()
        {
            return 1;
        }
    }

    public class Rectangle : Shape, IPolygon
    {
        public Rectangle()
            : base()
        {
            
        }
        ~Rectangle()
        {

        }

        float IPolygon.GetArea()
        {
            return height * length;
        }

        public override int TessellationCount()
        {
            return 2;
        }
    }
}
