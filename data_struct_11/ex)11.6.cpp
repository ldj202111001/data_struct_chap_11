/*
* ���α׷� ����: ���� ����� �̿��� �׷��� ǥ��
* �ǽ���¥: 2024 - 05 -24
* �й�: 202111001
* �̸�: �̵���
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

typedef char VtxData; // �׷��� ������ ������ �������� �ڷ���
int adj[MAX_VTXS][MAX_VTXS]; // ���� ���
int vsize; // ��ü ������ ����
VtxData vdata[MAX_VTXS]; // ������ ������ ������ �迭



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
        error("Error: ���� ���� �ʰ�\n");
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
            fscanf(fp, "%s", &str);
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

int visited[MAX_VTXS];
void reset_visited()
{
    int i;
    for (i = 0; i < vsize; i++)
        visited[i] = 0;
}

void DFS(int v)
{
    int w;
    visited[v] = 1;
    printf("%c ", vdata[v]);
    for (w = 0; w < vsize; w++)
        if (adj[v][w] != 0 && visited[w] == 0)
            DFS(w);
}

int main()
{ 
    load_graph("graph.txt");
    reset_visited();
    printf("DFS ==> ");
    DFS(0);
    printf("\n");
}