#include "Camera.h"

Camera::Camera()
{
	
}

void Camera::updateView(RenderWindow* window)
{
	window->setView(view);
}

void Camera::renderView(sf::Vector2f coords, int dir)
{
	moveRender(dir);
	
	if (borderRender(coords)) {
		if (!notMoving)
		{
			view.setCenter(coords);
		}
	}
}

void Camera::setCollisionFlag(bool flag)
{
	notMoving = flag;
}

void Camera::init(tmx::Object player_coords)
{
	fullscreen = false;
	notMoving = false;
	view.setSize(400 ,300);
	width = 400;
	
	height = 300;
	dir = 1;
	view.setCenter(player_coords.getPosition().x, player_coords.getPosition().y);
	cameraPreSet = 4;
	
}

void Camera::changeSize(int width, int height)
{
	
	if (width == 1920) {
		
		this->width = 480;
		this->height = 270;
	}
	else {
		this->width = width / 2;
		this->height = height / 2;
		
	}
	view.setSize(this->width, this->height);
	checkFullscreen();
}

void Camera::setCameraPreSet(int i)
{
	cameraPreSet = i;
}

void Camera::moveRender(int dir)
{
	if (this->dir != dir) notMoving = false;
	this->dir = dir;
}

bool Camera::borderRender(sf::Vector2f coords)
{
	if (cameraPreSet == 4 || cameraPreSet == 5 || cameraPreSet ==6)
	{
		if (cameraPreSet == 6 && width == view.getSize().x * 2) {
			view.setCenter(1113, 429);
			view.setSize(width, height);
		}
		
		if (coords.y <= height/2 || coords.x >= 1920 - width/2 || coords.x <= 720 + width/2 || coords.y >= 608 - height / 2)
		{
			if (coords.x >= 1920 - width / 2)
			{
				if (coords.y <= height / 2)
				{
					return 0;
				}
				else
				{
					if(!notMoving)
					{
					view.setCenter(view.getCenter().x, coords.y);
					return 0;
					}
					else return 0;
				}
			}
			if (coords.x <= 720 + width / 2)
			{
				if (coords.y <= height / 2)
				{
					return 0;
				}
				else
				{
					if (!notMoving)
					{
						view.setCenter(view.getCenter().x, coords.y);
						return 0;
					}
					else return 0;
				}
			}
			if (coords.y <= height / 2) {
				if (!notMoving)
				{
					view.setCenter(coords.x, view.getCenter().y);
					return 0;
				}
				else return 0;
			}
			if (coords.y >= 608 - height / 2)
			{
				if (!notMoving)
				{
					view.setCenter(coords.x, view.getCenter().y);
					return 0;
				}
				else return 0;
			}
		}

		return 1;
	}
	if ( cameraPreSet == 2)
	{ 
		
		if (coords.x <= 720 + width / 2 || coords.y <= 260 + height/2 || coords.y >=608 - height/2)
		{
			if(coords.x <= 720 + width / 2)
			{
				if (coords.y <= 260 + height / 2) return 0;
				if (coords.y >= 608 - height / 2) return 0;
				if (!notMoving)
				{
					view.setCenter(view.getCenter().x, coords.y);
					return 0;
				}
				else return 0;

			}
			if (coords.y <= 260 + height / 2)
			{
				if (!notMoving)
				{
					view.setCenter(coords.x, view.getCenter().y);
					return 0;

				}
				else return 0;
			}
			if (coords.y >= 608 - height / 2)
			{
				if (!notMoving)
				{
					view.setCenter(coords.x, view.getCenter().y);
					return 0;

				}
				else return 0;
			}

		}
		return 1;
	}

	if (cameraPreSet == 3)
	{
		
		if (coords.x >= 1920 - width / 2 || coords.y >=672 - height/2 || coords.y <= 256 + height/2)
		{
			if (coords.x >= 1920 - width / 2)
			{
				if (coords.y >= 672 - height / 2) return 0;
				if (coords.y <= 256 + height / 2) return 0;
				if (!notMoving)
				{
					view.setCenter(view.getCenter().x, coords.y);
					return 0;
				}
				else return 0;
			}
			if (coords.y >= 672 - height / 2)
			{
				if (!notMoving)
				{
					view.setCenter(coords.x, view.getCenter().y);
					return 0;
				}
				else return 0;
			}
			if (coords.y <= 256 + height / 2)
			{
				if (!notMoving)
				{
					view.setCenter(coords.x, view.getCenter().y);
					return 0;
				}
				else return 0;
			}
		}
		return 1;
	}
	if (cameraPreSet == 1)
	{
		
		
			view.setSize(width / 2, height / 2);
			if (view.getCenter().x <= 980 + width / 4 || view.getCenter().x >= 1252 - width / 4) { view.setCenter(1120, 583); }
			if (coords.y >= 832 - height / 4 || coords.x <= 992 + width / 4 || coords.x >= 1248 - width / 4)
			{
				if (coords.y >= 832 - height / 4)
				{
					if (coords.x <= 992 + width / 4) return 0;
					if (coords.x >= 1248 - width / 4) return 0;
					if (!notMoving)
					{
						view.setCenter(coords.x, view.getCenter().y);
						return 0;
					}
					else return 0;
				}
				if (coords.x <= 992 + width / 4)
				{
					if (!notMoving)
					{
						view.setCenter(view.getCenter().x, coords.y);
						return 0;
					}
					else return 0;
				}
				if (coords.x >= 1248 - width / 4)
				{
					if (!notMoving)
					{
						view.setCenter(view.getCenter().x, coords.y);
						return 0;
					}
					else return 0;
				}
			}
			return 1;
		
	}
	return 1;
}

void Camera::checkFullscreen()
{
	if (width == 480) fullscreen = true;
	else fullscreen = false;
}
