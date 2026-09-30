#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

struct Node {
    int x, y;
    int g; // ƒлина пути от начальной точки до текущей
    Node* parent; // ”казатель на предыдущий узел

    Node(int x, int y, int g, Node* parent) : x(x), y(y), g(g), parent(parent) {}

    // ќпредел€ем оператор сравнени€ дл€ использовани€ в приоритетной очереди
    bool operator<(const Node& other) const {
        return g > other.g; // »спользуем обратный пор€док, так как приоритетна€ очередь по умолчанию использует "меньше" дл€ наименьших элементов
    }
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void printPath(Node* node) {
    if (node == nullptr) {
        return;
    }
    printPath(node->parent);
}

int main() {
    // ¬вод количества разрешенных точек поворота, начальных и конечных координат
    int N, startX, startY, endX, endY;
    std::cin >> N >> startX >> startY >> endX >> endY;

    // —оздаем приоритетную очередь узлов
    std::priority_queue<Node> pq;

    // ƒобавл€ем начальный узел в приоритетную очередь
    pq.emplace(startX, startY, 0, nullptr);

    // ћассив дл€ хранени€ минимального числа поворотов до каждой клетки
    std::vector<std::vector<int>> turns(100, std::vector<int>(100, std::numeric_limits<int>::max()));
    turns[startX][startY] = 0;

    // ¬вод координат разрешенных точек поворота
    std::vector<std::pair<int, int>> allowedPoints;
    for (int i = 0; i < N; ++i) {
        int xi, yi;
        std::cin >> xi >> yi;
        allowedPoints.emplace_back(xi, yi);
    }

    // јлгоритм A*
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.x == endX && current.y == endY) {
            std::cout << turns[endX][endY] << std::endl;
            return 0;
        }

        // ѕеребираем соседние клетки
        std::vector<int> dx = {1, -1, 0, 0};
        std::vector<int> dy = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int nextX = current.x + dx[i];
            int nextY = current.y + dy[i];
            if (nextX >= 0 && nextX < 100 && nextY >= 0 && nextY < 100) {
                int newG = current.g + 1;
                if (newG < turns[nextX][nextY]) {
                    turns[nextX][nextY] = newG;
                    pq.emplace(nextX, nextY, newG + heuristic(nextX, nextY, endX, endY), &current);
                }
            }
        }

        // ѕровер€ем разрешенные точки поворота
        for (const auto& point : allowedPoints) {
            int newG = current.g + 1;
            if (newG < turns[point.first][point.second]) {
                turns[point.first][point.second] = newG;
                pq.emplace(point.first, point.second, newG + heuristic(point.first, point.second, endX, endY), &current);
            }
        }
    }

    std::cout << "-1" << std::endl;

    return 0;
}
