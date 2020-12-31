#include <SFML/Graphics.hpp>

using namespace sf;

int demo()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(500, 500), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// Задаем цвет фона
		window.clear(sf::Color::Black);

		
		// Отрисовка окна	
		window.display();
	}

	return 0;
}