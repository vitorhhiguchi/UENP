package estudos;

public class Dog {
    private String name;
    private int age;

    public Dog(String name, int age){
        this.name = name;
        this.age = age;
    }

    public void mijar(){
        System.out.println("Xiiii xiiii");
    }

    public void cagar(){
        System.out.println("Pooop poopp");
    }

    public void latir(){
        System.out.println("Au au au au");
    }

    public void comer(String comida, Dog dog){
        System.out.println(dog.name + " está comendo " + comida);
    }



    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public int getAge(){
        return age;
    }

    public void setAge(int age){
        this.age = age;
    }
}
