#include <iostream>
#include "geometry.h"

int main() {
  Polygon a({{0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}});
  Polygon b({{0, 0}, {10, 0}, {10, 10}, {5, 15}, {0, 10}});
  Polygon c({{0, 0}, {10, 0}, {10, 10}, {5, 15}, {0, 10}});
  c.rotate({-5, 0}, 90);
  Polygon d = c;
  d.scale({-5, 5}, 2);
  Polygon e({{0, 0}, {10, 0}, {5, 5}, {10, 10}, {0, 10}});
  Triangle f(Point(0, 0), Point(2, 0), Point(0, 2));
  Square* g = new Square(Point(0, 0), Point(2, 2));
  delete g;

  std::cout << a.isConvex() << '\n';
  std::cout << e.isConvex() << '\n';
  std::cout << a.isSimilarTo(b) << '\n';
  std::cout << a.isSimilarTo(e) << '\n';
  std::cout << a.isCongruentTo(b) << '\n';
  std::cout << c.isCongruentTo(b) << '\n';
  std::cout << (a == b) << '\n';
  std::cout << (c == b) << '\n';
  std::cout << (d == b) << '\n';
  std::cout << (d == d) << '\n';
  std::cout << a.area() << '\n';
  std::cout << '\n';

  Polygon a1({{0, 0}, {2, 0}, {1, 1}});
  Polygon a2({{0, 0}, {2, 0}, {2, 2}, {0, 2}});
  Polygon a3({{0, 0}, {2, 0}, {3, 2}, {1, 2}});
  Polygon a4({{0, 0}, {2, 0}, {3, 2}, {1, 4}, {-1, 2}});
  Polygon a5({{0, 0}, {2, 0}, {3, 2}, {1, 1}, {-1, 2}});
  Polygon a6({{0, 0}, {5, 0}, {5, -5}, {4, -1}});
  Polygon a7({{-2, 2}, {1, 2}, {6, 1}, {3, -1}, {-1, -2}});

  std::cout << a1.isConvex() << '\n';
  std::cout << a2.isConvex() << '\n';
  std::cout << a3.isConvex() << '\n';
  std::cout << a4.isConvex() << '\n';
  std::cout << a5.isConvex() << '\n';
  std::cout << a6.isConvex() << '\n';
  std::cout << a7.isConvex() << '\n';
  std::cout << '\n';

  Polygon b1({{1, 0}, {2, 0}, {3, -1}, {2, -2}});
  b1.reflect(Line(Point(0, 0), Point(1, 1)));

  std::cerr << "--------\n";
  Polygon b04({{-2, 2}, {1, 2}, {6, 1}, {3, -1}, {1, -1}, {-1, -2}});
  b04.rotate({0, 0}, 50);
  b04.scale({0, 0}, 3);
  Polygon b05({{9.27204, 15.7172}, {-2.6679, 6.15486}, {-8.45299, -0.739541}, {2.6679, -6.15486}, {4.2265, 0.369771}, {8.08322, 4.96604}});
  std::cout << b04.isSimilarTo(b05) << '\n';
  b05.scale({-2, 2}, 0.333333);
  b05.reflect(Line({0, 5}, {1, 8}));
  std::cout << b04.isCongruentTo(b05) << '\n';

  Polygon t2({{-2, 2}, {1, 2}, {6, 1}, {3, -1}, {1, -1}, {-1, -2}});
  Polygon t1({{9.27204, 15.7172}, {-2.6679, 6.15486}, {-8.45299, -0.739541}, {2.6679, -6.15486}, {4.2265, 0.369771}, {8.08322, 4.96604}});
  t1.scale({0, 0}, 0.33333);
  t1.rotate({0, 0}, -50);
  std::cout << t1.isCongruentTo(t2) << '\n';


  std::cerr << "\n";
  std::cerr << "\n";
  std::cerr << "--------\n";
  std::cout << '\n';
  Polygon t04({{-2, 2}, {1, 2}, {6, 1}, {3, -1}, {1, -1}, {-1, -2}});
  Polygon t04c = t04;
  t04.rotate({0, 0}, 50);
  t04.scale({0, 0}, 3);
  Polygon t05({{-2, 2}, {1, 2}, {6, 1}, {3, -1}, {1, -1}, {-1, -2}});
  std::cout << t04.getVertices()[0].x << '\n';
  std::cout << t04c.isSimilarTo(t05) << '\n';
  t05.scale({-2, 2}, 0.333333);
  t05.reflect(Line({0, 5}, {1, 8}));
  std::cout << t04c.isCongruentTo(t05) << '\n';

  Polygon c1({{0, 0}, {4, 0}, {4, 2}, {0, 2}});
  Polygon c2({{0, 0}, {4, 0}, {4, 2}, {0, 2}});
  Polygon c3({{0, 0}, {4, 0}, {4, 2}, {0, 2}});
  Polygon c4({{0, 0}, {4, 0}, {4, 2}, {0, 2}});
  Polygon c5({{0, 0}, {4, 0}, {4, 2}, {0, 2}});
  Polygon c0({{0, 0}, {8, 0}, {8, 2}, {0, 2}});  // !=
  c1.print();

  c2.scale({0, 0}, sqrt(2.));
  c2.rotate({0, 0}, 45);
  c2.print();  // ~

  c3.scale({-1, -2}, 2);
  //  c3.print();
  c3.reflect(Line({1, 3}, {2, 3}));
  //  c3.print();
  c3.scale({5, 2}, 0.5);
  c3.print();  // ~=

  c4.reflect(Line({0, 0}, {4, 2}));
  c4.print();  // ~=

  c5.rotate({0, 0}, -45);
  c5.print();  // ~=

  std::cout << c1.isCongruentTo(c2) << '\n';
  std::cout << c1.isCongruentTo(c3) << '\n';
  std::cout << c1.isCongruentTo(c4) << '\n';
  std::cout << c1.isCongruentTo(c5) << '\n';
  std::cout << c1.isSimilarTo(c2) << '\n';
  std::cout << c1.isSimilarTo(c3) << '\n';
  std::cout << c1.isSimilarTo(c4) << '\n';
  std::cout << c1.isSimilarTo(c5) << '\n';
  std::cout << c2.isCongruentTo(c1) << '\n';
  std::cout << c2.isCongruentTo(c3) << '\n';
  std::cout << c2.isCongruentTo(c4) << '\n';
  std::cout << c2.isCongruentTo(c5) << '\n';
  std::cout << c2.isSimilarTo(c1) << '\n';
  std::cout << c2.isSimilarTo(c3) << '\n';
  std::cout << c2.isSimilarTo(c4) << '\n';
  std::cout << c2.isSimilarTo(c5) << '\n';

  std::cout << c1.containsPoint({0, -1}) << '\n';
  std::cout << c1.containsPoint({0, 0}) << '\n';
  std::cout << c1.containsPoint({1, 1}) << '\n';
  std::cout << c1.containsPoint({4, 2}) << '\n';
  std::cout << c1.containsPoint({3, 1}) << '\n';
  std::cout << c1.containsPoint({5, 1}) << '\n';

  std::cout << '\n';

  Polygon d1({{0, 0}, {2, 0}, {2, 2}, {3, 3}, {2, 4}, {0, 4}});
  std::cout << d1.containsPoint({0, 0}) << '\n';
  std::cout << d1.containsPoint({1, 1}) << '\n';
  std::cout << d1.containsPoint({2, 2}) << '\n';
  std::cout << d1.containsPoint({2.5, 2.5}) << '\n';
  std::cout << d1.containsPoint({3, 3}) << '\n';
  std::cout << d1.containsPoint({5, 5}) << '\n';

  std::cout << '\n';

  std::cout << d1.containsPoint({1.1, 0.9}) << '\n';
  std::cout << d1.containsPoint({1, 2}) << '\n';
  std::cout << d1.containsPoint({1, 2.5}) << '\n';
  std::cout << d1.containsPoint({-1, 2.5}) << '\n';

  Rectangle r({0, 0}, {1, 1}, 1);
  std::cout << r.perimeter() << '\n';

  Square sq(Point(0, 0), Point(1, 1));
  Rectangle rect(Point(1, 0), Point(0, 1), 1);
  Shape& sh1 = sq;
  Shape& sh2 = rect;
  assert(sh1 == sh2);

  return 0;
}
