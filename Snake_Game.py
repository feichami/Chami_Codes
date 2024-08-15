import random
import time
import keyboard

UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)


class Snake: 
    
    def __init__(self, init_body, init_direction):
        self.body = init_body
        self.direction = init_direction

    def take_step(self, pos):
        self.body = self.body[1:] + [pos]

    def set_direction(self, direction):
        self.direction = direction

    def head(self):
        return self.body[-1]

class Apple:
    def __init__(self, height, width):
        self.position = (random.randint(0, height - 1), random.randint(0, width - 1))

    def spawn(self, height, width, snake_body):
        while True:
            position = (random.randint(0, height - 1), random.randint(0, width - 1))
            if position not in snake_body:
                self.position = position
                break


class Game:
    def __init__(self, height, width):
        self.height = height
        self.width = width
        self.snake = Snake([(0, 0), (1, 0), (2, 0), (3, 0)], RIGHT)
        self.apple = Apple(self.height, self.width)
        self.apple.spawn(self.height, self.width, self.snake.body)

    def check_collision(self):
        head_x, head_y = self.snake.head()

        if head_x < 0 or head_x >= self.height or head_y < 0 or head_y >= self.width:
            print("Game Over! You Hit the wall.")
            return True
        
        if self.snake.head() in self.snake.body[:-1]:
            print("Game Over! You hit yourself")
            return True

        if self.snake.head() == self.apple.position:
            print("Apple eaten!")
            self.apple.spawn(self.height, self.width, self.snake.body)
            self.snake.body = [self.snake.body[0]] + self.snake.body

        return False

    def board_matrix(self):
        matrix = [[' ' for _ in range (self.width)] for _ in range(self.height)]
        return matrix

    def render(self):
        print(f"Height: {self.height}")
        print(f"Width: {self.width}")

        matrix = self.board_matrix()

        for segment in self.snake.body:
            if 0 <= segment[0] < self.height and 0 <= segment[1] < self.width:
                matrix[segment[0]][segment[1]] = 1

        apple_pos = self.apple.position
        if 0 < apple_pos[0] < self.height and 0 <= segment[1] < self.width:
            matrix[apple_pos[0]][apple_pos[1]] = 2  

        for row in matrix:
            print(" ".join(map(str, row)))
        print()

    def move_snake(self):
        head_x, head_y = self.snake.head()
        dir_x, dir_y = self.snake.direction
        new_head = (head_x + dir_x, head_y + dir_y)

        if not self.check_collision():
            self.snake.take_step(new_head)

    def handle_input(self):
        if keyboard.is_pressed("up") and self.snake.direction != DOWN:
            self.snake.set_direction(UP)
        elif keyboard.is_pressed("down") and self.snake.direction != UP:
            self.snake.set_direction(DOWN)
        elif keyboard.is_pressed("left") and self.snake.direction != RIGHT:
            self.snake.set_direction(LEFT)
        elif keyboard.is_pressed("right") and self.snake.direction != LEFT:
            self.snake.set_direction(RIGHT)

    def run(self):
        while True:
            self.move_snake()
            self.render()

            time.sleep(0.5)

            if self.check_collision():
                break
            
game = Game(10, 20)

game.run()