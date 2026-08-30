import sonny
#from . import sonny

class Entity:
    def __init__(self, name, healthPoints, attack):
        self.name = name
        self.healthPoints = healthPoints
        self.attack = attack

    def fight(self, entity):
        print(f'{self.name} attack {entity.name} {entity.healthPoints}')


if __name__ == '__main__':

    hero = Entity('assassin', healthPoints = 100, attack = 50)
    monster = Entity('Poring', healthPoints = 50, attack = 10)

    while 1:
        hero.fight(monster)
