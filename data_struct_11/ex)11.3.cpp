/*
* 프로그램 내용: 인접 행렬을 이용한 그래프의 파일 입력 테스트 프로그램
* 실습날짜: 2024 - 05 - 24
* 학번: 202111001
* 이름: 이동재
*/
#define _CRT_SECURE_NO_WARNINGS
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
    printf("%d\n", vsize);
    for (i = 0; i < vsize; i++)
    {
        printf("%c", vdata[i]);
        for (j = 0; j < vsize; j++)
            printf(" %3d", adj[i][j]);
        printf("\n");
    }
}

void store_graph(char* filename)
{
    FILE* fp = fopen(filename, "w");
    if (fp != NULL) {
        print_graph( "");
        fclose(fp);
    }
}

void load_graph(const char* filename)
{
    int i, j, val, n;
    char str[80];
    FILE* fp = fopen(filename, "r");
    if (fp != NULL) 
    {
        init_graph();
        fscanf(fp, "%d", &n);

        for (i = 0; i < n; i++) 
        {
            fscanf(fp, "%s", str);
            insert_vertex(str[0]);
            for (j = 0; j < n; j++)
            {
                fscanf(fp, "%d", &val);
                if (val != 0)
                    insert_edge(i, j, val);
            }
           
        }
        fclose(fp);
    }
}

int main()
{
    load_graph("graph.txt");
    print_graph("그래프(인접행렬)\n");
}