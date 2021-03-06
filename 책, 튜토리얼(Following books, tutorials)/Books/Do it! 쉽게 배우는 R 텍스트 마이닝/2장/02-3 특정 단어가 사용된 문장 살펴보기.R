#문장 기준으로 토큰화하기

sentences_moon <- raw_moon %>%
  str_squish() %>%
  as_tibble() %>%
  unnest_tokens(input = value,
                output = sentence,
                token = "sentences")

sentences_moon
# # A tibble: 207 x 1
# sentence
# <chr>
#   1 정권교체 하겠습니다!
#   2 정치교체 하겠습니다!
#   3 시대교체 하겠습니다!
#   4 ‘불비불명(不飛不鳴)’이라는 고사가 있습니다.
# 5 남쪽 언덕 나뭇가지에 앉아, 3년 동안 날지도 울지도 않는 새.
# 6 그러나 그 새는 한번 날면 하늘 끝까지 날고, 한번 울면 천지를 뒤흔듭니다.~
#   7 그 동안 정치와 거리를 둬 왔습니다.
# 8 그러나 암울한 시대가 저를 정치로 불러냈습니다.
# 9 더 이상 남쪽 나뭇가지에 머무를 수 없었습니다.
# 10 이제 저는 국민과 함께 높이 날고 크게 울겠습니다.
# # ... with 197 more rows

# 특정 단어가 사용된 문장 추출하기

str_detect("치킨은 맛있다", "치킨")
# TRUE
  str_detect("치킨은 맛있다", "피자")
# FALSE
  
sentences_moon %>%
  filter(str_detect(sentence, "국민"))
# # A tibble: 19 x 1
# sentence
# <chr>
#   1 이제 저는 국민과 함께 높이 날고 크게 울겠습니다.
# 2 오늘 저는 제18대 대통령선거 출마를 국민 앞에 엄숙히 선언합니다.
# 3 존경하는 국민 여러분!
#   4 국민이 모두 아픕니다.
# 5 국민 한 사람 한 사람이 모두 아픕니다.
# 6 국민들에게 희망을 주는 정치가 절실하게 필요합니다.
# 7 국민의 뜻이 대통령의 길입니다.
# 8 저는 대선출마를 결심하고 국민 여러분께 출마선언문을 함께 쓰자고 제안 드렸습니다.~
#   9 시민의 한숨과 눈물을 닦아주지 못하는 정치가 있었고, 오히려 국민의 걱정거리가 된 초라한 정부의 모습도 있었습니다.~
#   10 상식이 통하는 사회, 권한과 책임이 비례하는 사회, 다름을 인정하는 세상, 개천에서 용이 날 수 있는 사회, 철학이 있는 나~
#   11 그러나 거창하게만 들리는 이 국가비전 역시 국민의 마음속에 있었습니다.
# 12 더욱 낮아지고 겸손해져서 국민의 마음속으로 들어가라.
# 13 국민들이 제게 준 가르침입니다.
# 14 국민의 뜻에서 대통령의 길을 찾겠습니다.
# 15 문화혁신을 통해 모든 국민의 창조성을 높이고 이를 통해 기술혁신과 신산업 형성의 역동적 파동을 일으키는 ‘창조적 성장’을 추~
#   16 이렇게 하면 국민의 살림이 서서히 나아질 것이며 5년 뒤에는 큰 성과가 나타날 것입니다.~
#   17 이명박 정부의 방해에도 불구하고 끝내 국민이 지켜준 세종시, 혁신도시를 지방 일자리 창출의 거점으로 만들겠습니다.~
#   18 존경하는 국민 여러분!
#   19 국민의 마음에서 길을 찾는 우리나라 대통령이 되겠습니다.

sentences_moon %>%
  filter(str_detect(sentence, "일자리"))

# # A tibble: 18 x 1
# sentence
# <chr>
#   1 빚 갚기 힘들어서, 아이 키우기 힘들어서, 일자리가 보이지 않아서 아픕니다.~
#   2 상생과 평화의 대한민국은 공평과 정의에 바탕을 두고, 성장의 과실을 함께 누리는 나라, 복지가 강한 나라, 일자리를 최우선에~
#   3 복지의 확대를 통해 보육, 교육, 의료, 요양 등 사회서비스 부문에 수많은 일자리가 생기고, 자영업에 몰려 있는 과잉인력을 ~
#   4 결국 복지국가로 가는 길은 사람에 대한 투자, 일자리 창출, 자영업 고통 경감, 삶의 질 향상 등 1석 4조의 효과를 만나는~
#   5 ‘일자리 정부’로 ‘일자리 혁명’을 이루겠습니다.
# 6 복지의 확대와 함께 저는 강력한 ‘일자리 혁명’을 이루고자 합니다.
# 7 지금 너무나 많은 젊은이들과 실업자, 비정규직 종사자, 근로능력이 있는 고령자들이 일할 수 있는 기회와 더 좋은 일자리를 요~
#   8 좋은 일자리 창출을 위해 비정규직의 정규직 전환 촉진, 비정규직에 대한 차별철폐, 근로시간 단축을 통한 신규고용 확대, 고용~
#   9 또한 정보통신 산업, 바이오산업, 나노 산업, 신재생에너지 산업, 문화산업과 콘텐츠산업 등 신산업을 크게 일으켜 일자리를 대~
#   10 그리고 앞에서 말한 보육, 교육, 의료, 복지 등 사회서비스 부문은 무궁무진한 잠재적 일자리의 보고입니다.~
#   11 일자리 없는 곳에서 희망을 찾을 수 없습니다.
# 12 지방 일자리에 대해 특별한 노력을 기울이겠습니다.
# 13 지역균형발전은 곧 산업 균형, 일자리 균형이 목표입니다.
# 14 이명박 정부의 방해에도 불구하고 끝내 국민이 지켜준 세종시, 혁신도시를 지방 일자리 창출의 거점으로 만들겠습니다.~
#   15 이 모든 정책의 실효성을 담보하기 위해 대통령이 되면 저는 가장 먼저 대통령 직속으로 <국가일자리위원회>를 설치하고 매달 ‘~
#   16 저는 먼 훗날 ‘일자리 혁명을 일으킨 대통령’으로 평가받기를 희망합니다.
# 17 또한 좋은 일자리와 산업혁신을 위해서는 평생학습체제가 뒷받침되어야 합니다.~
#   18 노인 일자리를 늘리고, 특히 그 연륜과 경험을 지역사회에 활용할 수 있는 방안도 마련하겠습니다.~
  
  