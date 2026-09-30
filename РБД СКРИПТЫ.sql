24----------------------------------------------------------------
create table Products (Model VARCHAR(50) NOT NULL, Maker VARCHAR(10) NOT NULL, Type_product VARCHAR(50) NOT NULL, PRIMARY KEY(Model));
create table Printers (Code_printer INTEGER NOT NULL, Model VARCHAR(50) NOT NULL, Color_printer VARCHAR(1) NOT NULL,
Type_printer VARCHAR(10) NOT NULL, Price_printer DECIMAL (10, 2) NULL, PRIMARY KEY (Code_printer));
create table Laptops (Code_laptop INTEGER NOT NULL, Model VARCHAR(50) NOT NULL, Speed_laptop SMALLINT NOT NULL,
RAM_laptop SMALLINT NOT NULL, HD_laptop REAL NOT NULL, Price_laptop DECIMAL (10,2) NULL,
Screen_laptop TINYINT NOT NULL, PRIMARY KEY (Code_laptop));
create table PCs (Code_pc INTEGER NOT NULL, Model VARCHAR(50) NOT NULL, Speed_oc SMALLINT NOT NULL,
RAM_pc SMALLINT NOT NULL, HD_pc REAL NOT NULL, CD_pc VARCHAR(10) NOT NULL, Price_pc DECIMAL (10,2) NULL,
PRIMARY KEY (Code_pc));


ALTER TABLE pcs ADD CONSTRAINT modelPCS FOREIGN KEY (Model) REFERENCES products(Model);
ALTER TABLE printers ADD CONSTRAINT modelPRINTERS FOREIGN KEY (Model) REFERENCES products(Model);
ALTER TABLE laptops ADD CONSTRAINT modelLAPTOPS FOREIGN KEY (Model) REFERENCES products(Model);


INSERT INTO Products (Model, Maker, Type_product) VALUES
('ModelP1', 'HP', 'Printer'),
('ModelP2', 'Canon', 'Printer'),
('ModelP3', 'Epson', 'Printer'),
('ModelP4', 'Brother', 'Printer'),
('ModelP5', 'Samsung', 'Printer'),
('ModelP6', 'Xerox', 'Printer'),
('ModelP7', 'Lexmark', 'Printer'),
('ModelP8', 'Ricoh', 'Printer'),
('ModelL1', 'Dell', 'Laptop'),
('ModelL2', 'Lenovo', 'Laptop'),
('ModelL3', 'HP', 'Laptop'),
('ModelL4', 'Asus', 'Laptop'),
('ModelL5', 'Acer', 'Laptop'),
('ModelL6', 'MSI', 'Laptop'),
('ModelL7', 'Apple', 'Laptop'),
('ModelL8', 'Microsoft', 'Laptop'),
('ModelC1', 'Acer', 'PC'),
('ModelC2', 'Asus', 'PC'),
('ModelC3', 'Dell', 'PC'),
('ModelC4', 'HP', 'PC'),
('ModelC5', 'Lenovo', 'PC'),
('ModelC6', 'Apple', 'PC'),
('ModelC7', 'MSI', 'PC'),
('ModelC8', 'Samsung', 'PC');


INSERT INTO Printers (Code_printer, Model, Color_printer, Type_printer, Price_printer) VALUES
(1, 'ModelP1', 'Y', 'Laser', 150.00),
(2, 'ModelP2', 'N', 'Inkjet', 85.00),
(3, 'ModelP3', 'Y', 'Laser', 200.00),
(4, 'ModelP4', 'Y', 'Laser', 120.00),
(5, 'ModelP5', 'N', 'Inkjet', 90.00),
(6, 'ModelP6', 'Y', 'Laser', 250.00),
(7, 'ModelP7', 'N', 'Inkjet', 110.00),
(8, 'ModelP8', 'Y', 'Laser', 180.00),
(9, 'ModelP1', 'N', 'Laser', 140.00),
(10, 'ModelP2', 'Y', 'Inkjet', 95.00),
(11, 'ModelP3', 'Y', 'Inkjet', 210.00),
(12, 'ModelP4', 'N', 'Laser', 130.00),
(13, 'ModelP5', 'Y', 'Laser', 190.00),
(14, 'ModelP6', 'N', 'Inkjet', 160.00),
(15, 'ModelP7', 'Y', 'Laser', 220.00),
(16, 'ModelP8', 'N', 'Inkjet', 170.00),
(17, 'ModelP3', 'Y', 'Laser', 210.00),
(18, 'ModelP4', 'N', 'Inkjet', 125.00),
(19, 'ModelP5', 'Y', 'Laser', 180.00),
(20, 'ModelP6', 'N', 'Laser', 150.00),
(21, 'ModelP7', 'Y', 'Inkjet', 140.00),
(22, 'ModelP8', 'Y', 'Laser', 190.00),
(23, 'ModelP3', 'N', 'Laser', 155.00),
(24, 'ModelP4', 'Y', 'Inkjet', 125.00),
(25, 'ModelP5', 'Y', 'Laser', 210.00);


INSERT INTO Laptops (Code_laptop, Model, Speed_laptop, RAM_laptop, HD_laptop, Price_laptop, Screen_laptop) VALUES
(1, 'ModelL1', 3200, 16, 512.0, 800.00, 15),
(2, 'ModelL2', 2400, 8, 256.0, 600.00, 14),
(3, 'ModelL3', 2800, 12, 512.0, 750.00, 15),
(4, 'ModelL4', 3000, 16, 1024.0, 1000.00, 17),
(5, 'ModelL5', 2600, 8, 512.0, 700.00, 14),
(6, 'ModelL6', 3200, 32, 2048.0, 2000.00, 17),
(7, 'ModelL7', 3400, 16, 1024.0, 1800.00, 16),
(8, 'ModelL8', 2200, 8, 256.0, 500.00, 13),
(9, 'ModelL1', 2800, 16, 512.0, 820.00, 15),
(10, 'ModelL2', 2600, 12, 1024.0, 920.00, 17),
(11, 'ModelL3', 2400, 8, 256.0, 580.00, 14),
(12, 'ModelL4', 3000, 16, 512.0, 800.00, 15),
(13, 'ModelL5', 2800, 12, 512.0, 750.00, 15),
(14, 'ModelL6', 3400, 32, 2048.0, 2100.00, 17),
(15, 'ModelL7', 2200, 8, 256.0, 520.00, 14),
(16, 'ModelL8', 3000, 16, 1024.0, 980.00, 17),
(17, 'ModelL1', 2400, 12, 512.0, 720.00, 15),
(18, 'ModelL2', 2600, 8, 256.0, 680.00, 14),
(19, 'ModelL3', 3000, 16, 512.0, 850.00, 15),
(20, 'ModelL4', 3200, 32, 2048.0, 2200.00, 17),
(21, 'ModelL5', 3400, 16, 1024.0, 1950.00, 16),
(22, 'ModelL6', 2400, 8, 256.0, 580.00, 14),
(23, 'ModelL7', 2800, 12, 512.0, 790.00, 15),
(24, 'ModelL8', 2600, 8, 256.0, 670.00, 14),
(25, 'ModelL1', 3200, 16, 512.0, 800.00, 15);


INSERT INTO PCs (Code_pc, Model, Speed_oc, RAM_pc, HD_pc, CD_pc, Price_pc) VALUES
(1, 'ModelC1', 3000, 16, 1024.0, 'DVD', 700.00),
(2, 'ModelC2', 2500, 8, 512.0, 'Blu-ray', 550.00),
(3, 'ModelC3', 3200, 16, 2048.0, 'DVD', 850.00),
(4, 'ModelC4', 2800, 12, 1024.0, 'DVD', 680.00),
(5, 'ModelC5', 2400, 8, 512.0, 'Blu-ray', 540.00),
(6, 'ModelC6', 3600, 32, 4096.0, 'DVD', 1200.00),
(7, 'ModelC7', 3400, 16, 1024.0, 'DVD', 850.00),
(8, 'ModelC8', 3000, 12, 512.0, 'Blu-ray', 620.00),
(9, 'ModelC1', 2600, 8, 256.0, 'DVD', 520.00),
(10, 'ModelC2', 3000, 16, 1024.0, 'DVD', 770.00),
(11, 'ModelC3', 2800, 12, 512.0, 'DVD', 670.00),
(12, 'ModelC4', 3200, 16, 1024.0, 'DVD', 900.00),
(13, 'ModelC5', 2400, 8, 256.0, 'Blu-ray', 540.00),
(14, 'ModelC6', 3600, 32, 2048.0, 'DVD', 1100.00),
(15, 'ModelC7', 3000, 16, 1024.0, 'DVD', 850.00),
(16, 'ModelC8', 2800, 12, 512.0, 'Blu-ray', 720.00),
(17, 'ModelC1', 2500, 8, 256.0, 'DVD', 500.00),
(18, 'ModelC2', 3400, 32, 2048.0, 'Blu-ray', 1150.00),
(19, 'ModelC3', 3200, 16, 1024.0, 'DVD', 870.00),
(20, 'ModelC4', 3000, 16, 1024.0, 'DVD', 800.00),
(21, 'ModelC5', 2600, 12, 512.0, 'Blu-ray', 670.00),
(22, 'ModelC6', 3600, 32, 2048.0, 'DVD', 1300.00),
(23, 'ModelC7', 3000, 16, 1024.0, 'DVD', 890.00),
(24, 'ModelC8', 3200, 16, 1024.0, 'Blu-ray', 950.00),
(25, 'ModelC1', 2800, 12, 512.0, 'DVD', 700.00);




SELECT 
    MIN(Code_pc) AS StartCode,
    AVG(Price_pc) AS AvgPrice
FROM PCs
GROUP BY (Code_pc - 1) DIV 6
ORDER BY StartCode;


???старая школа----------------------------------------------------------------
create table timepair (id INTEGER NOT NULL, start_pair time NOT NULL, end_pair time NOT NULL, primary key (id));
create table teacher (id INTEGER NOT NULL, first_name VARCHAR(50) NOT NULL, middle_name VARCHAR(50) NOT NULL, last_name VARCHAR(50) NOT NULL, primary key (id));
create table subject (id INTEGER NOT NULL, name VARCHAR(50) NOT NULL, primary key (id));
create table class (id INTEGER NOT NULL, name VARCHAR(50) NOT NULL, primary key(id));
create table shedule (id INTEGER NOT NULL, date date NOT NULL, class VARCHAR(50) NOT NULL, number_pair INTEGER NOT NULL,
teacher VARCHAR(50) NOT NULL, subject INTEGER NOT NULL, classroom VARCHAR(50) NOT NULL, primary key (id));
create table student_in_class (id INTEGER NOT NULL, class VARCHAR(50) NOT NULL, student VARCHAR(50) NOT NULL, primary key (id));
create table student (id INTEGER NOT NULL, first_name VARCHAR(50) NOT NULL, middle_name VARCHAR(50) NOT NULL, last_name VARCHAR(50) NOT NULL, birthday date NOT NULL, address VARCHAR(50) NOT NULL, primary key (id));
ALTER TABLE timepair ADD CONSTRAINT idTIMEPAIR FOREIGN KEY (id) REFERENCES shedule(id);
ALTER TABLE teacher ADD CONSTRAINT idTEACHER FOREIGN KEY (id) REFERENCES shedule(id);
ALTER TABLE subject ADD CONSTRAINT idSUBJECT FOREIGN KEY (id) REFERENCES shedule(id);
ALTER TABLE class ADD CONSTRAINT idCLASS FOREIGN KEY (id) REFERENCES shedule(id);


AirBnb--------------------------------------------------------------
use air;
select room_id, round(avg(rating)) as rating
from reservations join reviews on reservations.id = reviews.reservation_id
group by(room_id)


-- Создание таблиц для базы данных Airbnb
CREATE TABLE Users (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    email_verified_at DATE,
    passport VARCHAR(50),
    phone_number VARCHAR(20)
);
CREATE TABLE Rooms (
    id INT PRIMARY KEY,
    home_type VARCHAR(50),
    address VARCHAR(200),
    has_tv BOOLEAN,
    has_internet BOOLEAN,
    has_kitchen BOOLEAN,
    has_air_conditioner BOOLEAN,
    price INT,
    owner_id INT,
    latitude FLOAT,
    longitude FLOAT,
    FOREIGN KEY (owner_id) REFERENCES Users(id)
);
CREATE TABLE Reservations (
    id INT PRIMARY KEY,
    user_id INT,
    room_id INT,
    start_date DATE,
    end_date DATE,
    price INT,
    total INT,
    FOREIGN KEY (user_id) REFERENCES Users(id),
    FOREIGN KEY (room_id) REFERENCES Rooms(id)
);
CREATE TABLE Reviews (
    id INT PRIMARY KEY,
    reservation_id INT,
    rating INT,
    FOREIGN KEY (reservation_id) REFERENCES Reservations(id)
);
-- Наполнение таблиц данными
-- Пользователи
INSERT INTO Users (id, name, email, email_verified_at, passport, phone_number) VALUES
(1, 'Alice Johnson', 'alice@example.com', '2025-01-01', 'A1234567', '123-456-7890'),
(2, 'Bob Smith', 'bob@example.com', '2025-01-02', 'B2345678', '234-567-8901');
-- Комнаты
INSERT INTO Rooms (id, home_type, address, has_tv, has_internet, has_kitchen, has_air_conditioner, price, owner_id, latitude, longitude) VALUES
(1, 'Apartment', '123 Main St', TRUE, TRUE, TRUE, TRUE, 100, 1, 40.7128, -74.0060),
(2, 'House', '456 Elm St', FALSE, TRUE, TRUE, FALSE, 200, 2, 34.0522, -118.2437);
-- Бронирования
INSERT INTO Reservations (id, user_id, room_id, start_date, end_date, price, total) VALUES
(1, 1, 1, '2025-02-01', '2025-02-05', 100, 400),
(2, 2, 2, '2025-03-01', '2025-03-10', 200, 1800);
-- Отзывы
INSERT INTO Reviews (id, reservation_id, rating) VALUES
(1, 1, 5),
(2, 2, 4);
-- Запрос для вывода среднего рейтинга для комнат, которые арендовали хотя бы раз
SELECT 
    Rooms.id AS room_id, 
    ROUND(AVG(Reviews.rating)) AS average_rating
FROM Rooms
JOIN Reservations ON Rooms.id = Reservations.room_id
JOIN Reviews ON Reservations.id = Reviews.reservation_id
GROUP BY Rooms.id
ORDER BY average_rating DESC;
-- Запрос для вывода отзывов с рейтингом 5 на жильё по определённому адресу от имени определённого человека
SELECT
Reviews.id AS review_id,
Users.name AS user_name,
Rooms.address AS room_address,
Reviews.rating AS review_rating
FROM Reviews
JOIN Reservations ON Reviews.reservation_id = Reservations.id
JOIN Users ON Reservations.user_id = Users.id
JOIN Rooms ON Reservations.room_id = Rooms.id
WHERE Reviews.rating = 5
AND Rooms.address = '123 Main St'
AND Users.name = 'Alice Johnson';




Школа---------------------------------------------------------------------
use school;
select class.name, count(*) as count
from class join student_in_class on class.id=class
group by (class)
order by (count) desc
-- Запрос для подсчёта заполненности классов в порядке убывания
SELECT 
    Class.name AS class_name, 
    COUNT(Student_in_Class.student_id) AS student_count
FROM Class
LEFT JOIN Student_in_Class ON Class.id = Student_in_Class.class_id
GROUP BY Class.id, Class.name
ORDER BY student_count DESC;
---Запрос на получение предметов от определенного преподавателя
SELECT
Subject.name AS as_subjects
FROM Schedule
JOIN Teacher ON Schedule.teacher_id = Teacher.id
JOIN Subject ON Schedule.subject_id = Subject.id
WHERE Teacher.first_name = 'Anna' AND Teacher.middle_name = 'Maria' AND Teacher.last_name = 'Johnson'
ORDER BY Subject.name DESC;
---Запрос на узнавание имен тех, кто был на занятиях
SELECT DISTINCT 
    Student.first_name
FROM Student
JOIN Student_in_class ON Student.id = Student_in_class.student_id
JOIN Schedule ON Student_in_class.class_id = Schedule.class_id
JOIN Timepair ON Schedule.number_pair = Timepair.id
WHERE Timepair.start_pair >= '08:00:00' AND Timepair.end_pair <= '14:00:00'
ORDER BY Student.first_name ASC;


-- Создание таблиц для базы данных
CREATE TABLE Subject (
    id INT PRIMARY KEY,
    name VARCHAR(100)
);
CREATE TABLE Teacher (
    id INT PRIMARY KEY,
    first_name VARCHAR(50),
    middle_name VARCHAR(50),
    last_name VARCHAR(50)
);
CREATE TABLE Timepair (
    id INT PRIMARY KEY,
    start_pair TIME,
    end_pair TIME
);
CREATE TABLE Class (
    id INT PRIMARY KEY,
    name VARCHAR(50)
);
CREATE TABLE Schedule (
    id INT PRIMARY KEY,
    date DATE,
    class_id INT,
    number_pair INT,
    teacher_id INT,
    subject_id INT,
    classroom VARCHAR(50),
    FOREIGN KEY (class_id) REFERENCES Class(id),
    FOREIGN KEY (teacher_id) REFERENCES Teacher(id),
    FOREIGN KEY (subject_id) REFERENCES Subject(id)
);
CREATE TABLE Student (
    id INT PRIMARY KEY,
    first_name VARCHAR(50),
    middle_name VARCHAR(50),
    last_name VARCHAR(50),
    birthday DATE,
    address VARCHAR(200)
);
CREATE TABLE Student_in_Class (
    id INT PRIMARY KEY,
    student_id INT,
    class_id INT,
    FOREIGN KEY (student_id) REFERENCES Student(id),
    FOREIGN KEY (class_id) REFERENCES Class(id)
);
-- Наполнение таблиц примерами данных
-- Предметы
INSERT INTO Subject (id, name) VALUES
(1, 'Mathematics'),
(2, 'History'),
(3, 'Biology');
-- Учителя
INSERT INTO Teacher (id, first_name, middle_name, last_name) VALUES
(1, 'John', 'Edward', 'Smith'),
(2, 'Anna', 'Maria', 'Johnson'),
(3, 'Robert', 'William', 'Brown');
-- Временные пары
INSERT INTO Timepair (id, start_pair, end_pair) VALUES
(1, '08:00:00', '08:45:00'),
(2, '09:00:00', '09:45:00'),
(3, '10:00:00', '10:45:00');
-- Классы
INSERT INTO Class (id, name) VALUES
(1, 'Class A'),
(2, 'Class B');
-- Расписание для классов
INSERT INTO Schedule (id, date, class_id, number_pair, teacher_id, subject_id, classroom) VALUES
(1, '2025-01-21', 1, 1, 1, 1, 'Room 101'),
(2, '2025-01-21', 1, 2, 2, 2, 'Room 102'),
(3, '2025-01-21', 2, 3, 3, 3, 'Room 103');
-- Ученики
INSERT INTO Student (id, first_name, middle_name, last_name, birthday, address) VALUES
(1, 'Alice', 'Marie', 'Taylor', '2010-05-14', '123 Main St'),
(2, 'Bob', 'James', 'Anderson', '2011-03-22', '456 Elm St'),
(3, 'Charlie', 'Joseph', 'Davis', '2010-08-30', '789 Oak St'),
(4, 'Diana', 'Louise', 'Clark', '2011-01-17', '321 Pine St');
-- Ученики в классах
INSERT INTO Student_in_Class (id, student_id, class_id) VALUES
(1, 1, 1),
(2, 2, 1),
(3, 3, 2),
(4, 4, 2);
-- Запрос для подсчёта заполненности классов в порядке убывания
SELECT 
    Class.name AS class_name, 
    COUNT(Student_in_Class.student_id) AS student_count
FROM Class
LEFT JOIN Student_in_Class ON Class.id = Student_in_Class.class_id
GROUP BY Class.id, Class.name
ORDER BY student_count DESC;




Семья----------------------------------------------------------------------
select family_member, sum(total) as total_price
from payments
group by family_member
having sum(total) > 1000;
-- Таблица членов семьи
CREATE TABLE FamilyMembers (
    member_id INT PRIMARY KEY,
    status VARCHAR(50),
    member_name VARCHAR(100),
    birthday DATE
);


-- Таблица типов товаров
CREATE TABLE GoodTypes (
    good_type_id INT PRIMARY KEY,
    good_type_name VARCHAR(100)
);


-- Таблица товаров
CREATE TABLE Goods (
    good_id INT PRIMARY KEY,
    good_name VARCHAR(100),
    type INT,
    FOREIGN KEY (type) REFERENCES GoodTypes(good_type_id)
);


-- Таблица платежей
CREATE TABLE Payments (
    payment_id INT PRIMARY KEY,
    family_member INT,
    good INT,
    amount INT,
    unit_price DECIMAL(10, 2),
    date DATETIME,
    FOREIGN KEY (family_member) REFERENCES FamilyMembers(member_id),
    FOREIGN KEY (good) REFERENCES Goods(good_id)
);
-- Члены семьи
INSERT INTO FamilyMembers (member_id, status, member_name, birthday) VALUES
(1, 'Father', 'John Doe', '1970-01-01'),
(2, 'Mother', 'Jane Doe', '1975-02-01'),
(3, 'Son', 'Jake Doe', '2000-06-15');


-- Типы товаров
INSERT INTO GoodTypes (good_type_id, good_type_name) VALUES
(1, 'Electronics'),
(2, 'Groceries'),
(3, 'Clothing');


-- Товары
INSERT INTO Goods (good_id, good_name, type) VALUES
(1, 'Laptop', 1),
(2, 'Milk', 2),
(3, 'T-shirt', 3);


-- Платежи
INSERT INTO Payments (payment_id, family_member, good, amount, unit_price, date) VALUES
(1, 1, 1, 1, 1200.00, '2023-01-01 10:00:00'),
(2, 2, 2, 10, 1.50, '2023-01-02 12:00:00'),
(3, 3, 3, 2, 25.00, '2023-01-03 14:00:00');
SELECT DISTINCT 
    FamilyMembers.member_name 
FROM FamilyMembers
JOIN Payments ON FamilyMembers.member_id = Payments.family_member
WHERE Payments.amount * Payments.unit_price > 1000;
-- Запрос для вычисления средней стоимости икры
SELECT 
    AVG(unit_price) AS cost
FROM Payments
JOIN Goods ON Payments.good = Goods.good_id
WHERE Goods.good_name IN ('Red Caviar', 'Black Caviar');
-- Запрос для нахождения самого дорогого продукта и его стоимости
SELECT
Goods.good_name,
MAX(Payments.unit_price) AS unit_price
FROM Payments
JOIN Goods ON Payments.good = Goods.good_id
GROUP BY Goods.good_name
ORDER BY unit_price DESC
LIMIT 1;


Авиаперелеты---------------------------------------------------------------
SELECT
p1.name AS passengerName1,
p2.name AS passengerName2,
COUNT(*) AS count
FROM Pass_in_trip pit1
JOIN Pass_in_trip pit2 ON pit1.trip_id = pit2.trip_id AND pit1.passenger_id < pit2.passenger_id
JOIN Passenger p1 ON pit1.passenger_id = p1.id
JOIN Passenger p2 ON pit2.passenger_id = p2.id
GROUP BY p1.name, p2.name
HAVING COUNT(*) >= 2;
---------------------------------------------------------------


use avia;
select town_to, timestampdiff(hour, time_in, time_out) as flight_time
from trip
where town_from='Moscow'
-- Запрос для определения городов назначения и времени полета из Москвы
SELECT 
    town_to AS town,
    SEC_TO_TIME(TIME_TO_SEC(TIMEDIFF(time_in, time_out))) AS flight_time
FROM Trip
WHERE town_from = 'Moscow';
-- Запрос для вывода имён пассажиров, улетевших в Москву на самолёте Tu-134
SELECT 
    Passenger.name AS passenger_name
FROM Passenger
JOIN Pass_in_trip ON Passenger.id = Pass_in_trip.passenger_id
JOIN Trip ON Pass_in_trip.trip_id = Trip.id
WHERE Trip.town_to = 'London' AND Trip.plane = 'Airbus A320';




-- Создание базы данных авиаперелетов
CREATE TABLE Company (
    id INT PRIMARY KEY,
    name VARCHAR(100)
);
CREATE TABLE Passenger (        
    id INT PRIMARY KEY,
    name VARCHAR(100)
);
CREATE TABLE Trip (
    id INT PRIMARY KEY,
    company_id INT,
    plane VARCHAR(50),
    town_from VARCHAR(100),
    town_to VARCHAR(100),
    time_out TIME,
    time_in TIME,
    FOREIGN KEY (company_id) REFERENCES Company(id)
);
CREATE TABLE Pass_in_trip (
    id INT PRIMARY KEY,
    trip_id INT,
    passenger_id INT,
    place VARCHAR(10),
    FOREIGN KEY (trip_id) REFERENCES Trip(id),
    FOREIGN KEY (passenger_id) REFERENCES Passenger(id)
);
-- Наполнение таблиц данными
-- Компании
INSERT INTO Company (id, name) VALUES
(1, 'Airline A'),
(2, 'Airline B');
-- Пассажиры
INSERT INTO Passenger (id, name) VALUES
(1, 'John Doe'),
(2, 'Jane Smith');
-- Рейсы
INSERT INTO Trip (id, company_id, plane, town_from, town_to, time_out, time_in) VALUES
(1, 1, 'Boeing 737', 'Moscow', 'New York', '10:00:00', '20:00:00'),
(2, 2, 'Airbus A320', 'Moscow', 'London', '12:00:00', '15:00:00');
-- Билеты
INSERT INTO Pass_in_trip (id, trip_id, passenger_id, place) VALUES
(1, 1, 1, '12A'),
(2, 2, 2, '14B');