# APP Project

APP[모듈명] 프로젝트

## 프로젝트 구조

- 공통 설정
  - .gitignore : 깃에 안올려야 하는 파일 목록
  - .gitattributes : 깃 기본설정
  - .gitmodules : 깃 서브모듈
  - .clang-format : 자동 포매팅 설정
- common : 공통 모듈
- hal : 하드웨어 인터페이스
- osal : OS 인터페이스
- coal : 통신 인터페이스
- app : 메인 어플리케이션
