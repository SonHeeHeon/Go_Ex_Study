# Union Find
합집합 찾기  
여러개의 노드가 존재할 때 두개의 노드를 선택해서 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘

## 목표
유니온 파인드 알고리즘을 이해하고 구현하기

## 기초 지식(?) 먼저 알아야하는것? 뭐더라
- Disjoint Set
    - 정의  
        서로 중복되지 않는 부분 집합들로 나눠진 원소들에 대한 정보를 저장하고 조작하는 자료구조  
        즉, 공통 원소가 없는 상호배타적인 부분집합들로 나눠진 원소들에 대한 자료구조  
        => 서로소 집합 자료구조

## 정의
Disjoint Set을 표현할 때 사용하는 알고리즘  
- 배열,연결 리스트로도 가능하지만 가장 효율적인 트리를 이용해 구현
    - 트리로 구현해야 하는 이유
        1. 배열
            union(x,y)를 할때 배열의 모든 원소를 순회하면서 y의 집합 번호를 x의 집합 번호로 변경한다.
        2. 트리
            x,y의 루트 노드를 찾고 다르면 y를 x의 자손으로 넣어 두 트리를 합한다.


## 연산 방법
- make-set(x)
    - 초기화
    - x를 유일한 원소로 하는 새로운 집합을 만든다
- union(x,y)
    - 합하기
    - x가 속한 집합과 y가 속한 집합을 합친다. 즉, x와 y가 속한 두 집합을 합치는 연산
- find(x)
    - 찾기
    - x가 속한 집합의 대표값(루트 노드 값)을 반환한다. 즉, x가 어떤 집합에 속해 있는지 찾는 연산


