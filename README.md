# ROOKIE HERO
> 프로젝트 제작 기간 : 2025.01.10 ~ 2025.01.16


## 프로젝트 소개

### 프롤로그
![Prolouge](https://github.com/solie75/Text_RPG/blob/main/ReadMeImage/Prolouge.jpg)
> 현재 공국은 마왕의 흉악한 주술로 인해 몬스터가 창궐하여, 각 성과 도시, 촌락에 근심이 그칠 날이 없다. 이에 본국은 몬스터를 토벌하고, 마왕을 소멸시키기 위해 용사를 선발하고자 한다. 당신은 던전에 도전에 영웅의 자격을 증명하려고 한다. 그대의 도전이 공국에 평화를 가져다주기를!


왕의 부름으로 던전을 토벌하러 간 용사...   
하지만 던전에서의 첫 전투는 처참히 패배하고 말았다.   
마을 사람들의 도움으로 다시 일어난 용사는 레벨 10으로 성장하여 보스 몬스터를 물리칠 수 있을 것인가?   


### Text RPG란?
레벨업과 전략적 아이템 관리를 통해 보스를 물리치는 텍스트 기반 로그라이크 RPG 게임 입니다.
![GameStructureDiagram](https://github.com/solie75/Text_RPG/blob/main/ReadMeImage/Game%20Structure%20Diagram.png)
게임을 시작하면 환영 문구와 함께 플레이어의 이름을 입력받습니다.


전투는 

## 개발 환경
* C++ 20
* Visual Studio 2022

## 프로젝트 구조

## 핵심 로직/클래스 설명
### Manager
### Player
### Monster
### Battle
### Stage
### Shop

## 과제 추가 구현 사항
### ASCII Art를 이용한 화면 구성
텍스트 기반 게임이지만 ASCII Art를 이용하여 몰입할 수 있는 게임을 만들었습니다.
![RoyalMissive](https://github.com/solie75/Text_RPG/blob/main/ReadMeImage/Royal%20Missive.png)


각 Stage에는 모두 StageRender라는 가상함수를 구현해야 하도록 되어 있습니다. StageRender 함수에서는 해당 스테이지에서 보여줘야하는 200*50 화면을 그리도록 하였습니다. 아스키 아트는 아래 두 링크를 통해 이미지를 아스키 아트로 생성하기도 하고 텍스트를 아스키 아트로 만들어 사용하기도 하였습니다. 또는 필요한 화면 구성이 있다면 직접 문자로 그림을 그려 사용하기도 하였습니다.
* [그림->아스키아트 링크](https://wepplication.github.io/tools/asciiArtGen/?size=190&color=false&fileupload=)
* [텍스트->아스키아트 링크](https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20)


또한 대사창을 넘기거나 애니메이션이 필요한 경우 여러 개의 화면을 찍어 switch문이나 if문을 이용하여 화면이 전환되도록 하였습니다. 애니메이션의 경우 렌더할 화면과 화면 사이에 시간이 필요하기 때문에 잠시 대기했다가 화면이 바뀌도록 구현하였습니다.

### 튜토리얼 구현
게임의 초반에 바로 던전에 들어가는 것이 아닌 튜토리얼이 존재합니다. 튜토리얼은 플레이어가 해당 스테이지에서 어떤 행동을 할 수 있는지 알려주고 세계관을 설명해주는 역할을 합니다.



같은 스테이지지만 StageManager에 있는 bool타입 변수 IsDoneTutorialStage의 값에 따라 튜토리얼 화면이 렌더 되고 아니고가 결정됩니다. isDoneTutorialStage가 false라면 아직 튜토리얼 상태를 의미하고 true라면 튜토리얼이 끝난 상태를 의미한다. IsDoneTutorialStage는 false로 초기화되며 CVillageStage(빌리지 스테이지)에서 튜토리얼 대사가 진행된 후 true로 바뀌면서 이후에는 튜토리얼이 뜨지 않게 됩니다.

### 매니저의 분할
### 빌리지 스테이지 구현
### 교회 스테이지 구현
### 상점 판매 제한
### 팩토리 메서드를 이용한 몬스터 생성
몬스터를 생성할 때 이후 몬스터 추가를 용이하게 하기 위해 팩토리 메서드 패턴으로 구현하였습니다.

### 몬스터 가죽 아이템 추가

## 주의사항
* 마스터 모드 : Z를 누르시면 마스터 모드로 플레이가 가능합니다. 플레이어 스탯을 최대치로 설정하고 바로 보스 던전에 입장이 가능합니다.

## 관련 링크
* [팀 노션 링크](https://teamsparta.notion.site/1-14-4a713f7f889144f099875472d2bd38ed)

## 회고

https://github.com/solie75/Text_RPG/blob/main/KPT%20(%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8%20%ED%9A%8C%EA%B3%A0).md

## 팀원
|이름|역할|작업기능|
|--------|--------|---------------|---------------|
|신중은|팀장|구조 설계 및 스테이지 제작 등|[TEST](https://github.com/solie75)|
|전보경|팀원|상점 화면 구성 및 코드 보조 등|[TEST](https://github.com/solie75)|
|김채영|팀원|몬스터 생성 및 배틀 등|[TEST](https://github.com/solie75)|
|장진우|팀원|던전 및 캐릭터 등|[TEST](https://github.com/solie75)|
|장세희|팀원|아이템 및 상점 등|[TEST](https://github.com/solie75)|
