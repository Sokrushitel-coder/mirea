class Dog {
    private String nickname;
    private int age;

    public Dog(String nickname, int age) {
        this.nickname = nickname;
        this.age = age;
    }

    public String getNickname() { return nickname; }
    public void setNickname(String nickname) { this.nickname = nickname; }
    public int getAge() { return age; }
    public void setAge(int age) { this.age = age; }

    public int getHumanAge() {
        return age * 7;
    }

    @Override
    public String toString() {
        return "Dog [Nickname: " + nickname + ", Age: " + age + " (Dog Years), Human Age: " + getHumanAge() + " (Human Years)]";
    }
}

public class DogKennel {
    private Dog[] dogs;
    private int numDogs;

    public DogKennel(int capacity) {
        dogs = new Dog[capacity];
        numDogs = 0;
    }

    public void addDog(Dog dog) {
        if (numDogs < dogs.length) {
            dogs[numDogs] = dog;
            numDogs++;
        } else {
            System.out.println("The kennel is full. Cannot add more dogs.");
        }
    }

    public void displayDogs() {
        for (int i = 0; i < numDogs; i++) {
            System.out.println(dogs[i]);
        }
    }

    public static void main(String[] args) {
        DogKennel kennel = new DogKennel(3);
        Dog dog1 = new Dog("Buddy", 3);
        Dog dog2 = new Dog("Max", 5);
        Dog dog3 = new Dog("Lucy", 2);

        kennel.addDog(dog1);
        kennel.addDog(dog2);
        kennel.addDog(dog3);

        kennel.displayDogs();
    }
}
