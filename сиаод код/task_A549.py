# Создать список (каталог мобильных приложений), состоящий из словарей (приложение). Словари должны содержать как минимум 5 полей
# (например, номер, название, рейтинг...). В список добавить хотя бы 10 словарей.
# Конструкция вида:
# apps = [{"id" : 123456, "title" : "Google Play", "rating" : 4.9,...} , {...}, {...}, ...]
# Реализовать функции:
# – вывода информации о всех приложениях;
# – вывода информации о приложении по введенному с клавиатуры номеру;
# – вывода количества приложений, с оценкой выше введённого;
# – обновлении всей информации о приложении по введенному номеру;
# – удалении приложения по номеру.
# Провести тестирование функций.

# Создание списка приложений
apps = [
    {"id": 1, "title": "Instagram", "rating": 4.5, "downloads": 1000000000, "category": "Social"},
    {"id": 2, "title": "YouTube", "rating": 4.7, "downloads": 5000000000, "category": "Video"},
    {"id": 3, "title": "Facebook", "rating": 4.0, "downloads": 2000000000, "category": "Social"},
    {"id": 4, "title": "WhatsApp", "rating": 4.2, "downloads": 5000000000, "category": "Communication"},
    {"id": 5, "title": "Google Maps", "rating": 4.3, "downloads": 1000000000, "category": "Maps"},
    {"id": 6, "title": "Gmail", "rating": 4.6, "downloads": 1000000000, "category": "Communication"},
    {"id": 7, "title": "TikTok", "rating": 4.4, "downloads": 1000000000, "category": "Social"},
    {"id": 8, "title": "Netflix", "rating": 4.1, "downloads": 500000000, "category": "Entertainment"},
    {"id": 9, "title": "Twitter", "rating": 3.9, "downloads": 500000000, "category": "Social"},
    {"id": 10, "title": "Amazon", "rating": 4.8, "downloads": 1000000000, "category": "Shopping"}
]

# Функция вывода информации о всех приложениях
def print_apps(apps_list):
    for app in apps_list:
        print(f"{app['id']}: {app['title']}, rating: {app['rating']}, downloads: {app['downloads']}, category: {app['category']}")

# Функция вывода информации о приложении по введенному номеру
def print_app_by_id(apps_list, app_id):
    for app in apps_list:
        if app['id'] == app_id:
            print(f"{app['id']}: {app['title']}, rating: {app['rating']}, downloads: {app['downloads']}, category: {app['category']}")
            return
    print(f"App with id {app_id} not found")

# Функция вывода количества приложений, с оценкой выше введенного
def print_apps_above_rating(apps_list, rating):
    count = 0
    for app in apps_list:
        if app['rating'] > rating:
            count += 1
    print(f"There are {count} apps with a rating above {rating}")

# Функция обновления всей информации о приложении по введенному номеру
def update_app_by_id(apps_list, app_id):
    for app in apps_list:
        if app['id'] == app_id:
            app['title'] = input("Enter new title: ")
            app['rating'] = float(input("Enter new rating: "))
            app['downloads'] = int(input("Enter new downloads: "))
            app['category'] = input("Enter new category: ")
def delete_app_by_id(apps_list,app_id):
    for app in apps_list:
        if app['id'] == app_id:
            apps_list.remove(app)
##print_apps(apps)
##print_app_by_id(apps,1)
##print_apps_above_rating(apps,4.5)
##update_app_by_id(apps,1)
##print_apps(apps)
##delete_app_by_id(apps,1)
##print_apps(apps)
