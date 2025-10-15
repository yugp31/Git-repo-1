#This is a snake game
import pygame
import random
from collections import deque

# Initialize Pygame
pygame.init()

# Constants
WINDOW_SIZE = 600
GRID_SIZE = 20
GRID_WIDTH = WINDOW_SIZE // GRID_SIZE
GRID_HEIGHT = WINDOW_SIZE // GRID_SIZE

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Create the game window
screen = pygame.display.set_mode((WINDOW_SIZE, WINDOW_SIZE))
pygame.display.set_caption("Snake Game")

class Snake:
    def __init__(self):
        # Initialize snake's body as a deque (double-ended queue)
        self.body = deque([(GRID_WIDTH//2, GRID_HEIGHT//2)])
        self.direction = (1, 0)  # Start moving right
        self.grow = False

    def move(self):
        # Calculate new head position
        new_head = (
            (self.body[-1][0] + self.direction[0]) % GRID_WIDTH,
            (self.body[-1][1] + self.direction[1]) % GRID_HEIGHT
        )
        
        # Check for self collision
        if new_head in self.body:
            return False

        # Add new head
        self.body.append(new_head)
        
        # Remove tail if not growing
        if not self.grow:
            self.body.popleft()
        else:
            self.grow = False
            
        return True

    def change_direction(self, new_direction):
        # Prevent 180-degree turns
        if (new_direction[0] * -1, new_direction[1] * -1) != self.direction:
            self.direction = new_direction

class Game:
    def __init__(self):
        self.snake = Snake()
        self.food = self.generate_food()
        self.score = 0
        self.clock = pygame.time.Clock()
        
    def generate_food(self):
        while True:
            food = (random.randint(0, GRID_WIDTH-1), 
                   random.randint(0, GRID_HEIGHT-1))
            if food not in self.snake.body:
                return food

    def update(self):
        # Move snake
        if not self.snake.move():
            return False

        # Check for food collision
        if self.snake.body[-1] == self.food:
            self.snake.grow = True
            self.food = self.generate_food()
            self.score += 1

        return True

    def draw(self):
        screen.fill(BLACK)
        
        # Draw snake
        for segment in self.snake.body:
            pygame.draw.rect(screen, GREEN,
                           (segment[0] * GRID_SIZE,
                            segment[1] * GRID_SIZE,
                            GRID_SIZE - 1, GRID_SIZE - 1))
        
        # Draw food
        pygame.draw.rect(screen, RED,
                        (self.food[0] * GRID_SIZE,
                         self.food[1] * GRID_SIZE,
                         GRID_SIZE - 1, GRID_SIZE - 1))
        
        pygame.display.flip()

    def run(self):
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_UP:
                        self.snake.change_direction((0, -1))
                    elif event.key == pygame.K_DOWN:
                        self.snake.change_direction((0, 1))
                    elif event.key == pygame.K_LEFT:
                        self.snake.change_direction((-1, 0))
                    elif event.key == pygame.K_RIGHT:
                        self.snake.change_direction((1, 0))

            if not self.update():
                print(f"Game Over! Score: {self.score}")
                running = False

            self.draw()
            self.clock.tick(10)  # Control game speed

if __name__ == "__main__":
    game = Game()
    game.run()
    pygame.quit()
