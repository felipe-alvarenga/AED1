#include <stdio.h>

int main() {
    int h_inicial, m_inicial, h_final, m_final;
    int duracao_hora, duracao_minuto;

    // Leitura dos horários de início e fim
    scanf("%d %d %d %d", &h_inicial, &m_inicial, &h_final, &m_final);

    // Calculando a duração em minutos
    int inicio_total_minutos = h_inicial * 60 + m_inicial;
    int fim_total_minutos = h_final * 60 + m_final;

    // Se a hora final for menor que a hora inicial, significa que passou para o dia seguinte
    if (fim_total_minutos <= inicio_total_minutos) {
        fim_total_minutos += 24 * 60; // Adiciona 24 horas (em minutos)
    }

    // Calculando a diferença
    int duracao_total_minutos = fim_total_minutos - inicio_total_minutos;
    duracao_hora = duracao_total_minutos / 60; // Converte minutos para horas
    duracao_minuto = duracao_total_minutos % 60; // Pega os minutos restantes

    // Exibe o resultado
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_hora, duracao_minuto);

    return 0;
}
