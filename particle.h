#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct {
    float x, y; // Положение частицы
    float vx, vy; // Скорость частицы
    float radius; // Размер частицы
    float r, g, b; // Цвет частицы
} Particle;

#endif // PARTICLE_H
