import java.util.Date;

public class Work1 {
    public static void main(String[] args) {
        String developerName = "Кривосудов Р.Д.";
        Date startDate = new Date();
        long submissionTimeMillis = System.currentTimeMillis();
        Date submissionDate = new Date(submissionTimeMillis);

        System.out.println("Фамилия разработчика: " + developerName);
        System.out.println("Дата и время получения задания: " + startDate);
        System.out.println("Дата и время сдачи задания: " + submissionDate);
    }
}