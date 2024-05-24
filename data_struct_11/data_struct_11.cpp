﻿/*
* 프로그램 내용: 인접 행렬을 이용한 그래프 표현
* 실습날짜: 2024 - 05 -24
* 학번: 202111001
* 이름: 이동재
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256

void error(const char str[])
{
    printf("%s\n", str);
    exit(1);
}

typedef char VtxData; // 그래프 정점에 저장할 데이터의 자료형
int adj[MAX_VTXS][MAX_VTXS]; // 인접 행렬
int vsize; // 전체 정점의 개수
VtxData vdata[MAX_VTXS]; // 정점에 저장할 데이터 배열



int is_empty_graph() { return (vsize == 0); }
int is_full_graph() { return (vsize >= MAX_VTXS); }

void init_graph() 
{
    int i, j;
    vsize = 0;
    for (i = 0; i < MAX_VTXS; i++)
        for (j = 0; j < MAX_VTXS; j++)
            adj[i][j] = 0;
}


void insert_vertex(char name) {
    if (is_full_graph())
        error("Error: 정점 개수 초과\n");
    else
        vdata[vsize++] = name;
}
void insert_edge(int u, int v, int val)
{
    adj[u][v] = val;
}
void insert_edge2(int u, int v, int val)
{
    adj[u][v] = adj[v][u] = val;
}

void print_graph(const char* msg)
{
    int i, j;
    printf("%s", msg);
    printf
}

int main()
{
    int i;
    init_graph();
    for (i = 0; i < 4; i++)
        insert_vertex('A' + i);
    insert_edge2(0, 1, 1);
    insert_edge2(0, 3, 1);
    insert_edge2(1, 2, 1);
    insert_edge2(1, 3, 1);
    insert_edge2(2, 3, 1);
    //print_graph(stdout, "그래프(인접행렬)\n");
}