# VSA1 - Laboratoriya İşi 2 (Lab 2)
**Tələbə:** Səid Saruxanov  
**Mövzu:** Məlumat Strukturları (Linked List, Stack, Queue) və Real Həyat Tətbiqləri (STL istifadə edilmədən)

Bu repozitoriyada C++ dilində standart şablon kitabxanası (STL) istifadə edilmədən, göstəricilər (pointers) və qovşaqlar (nodes) vasitəsilə sıfırdan reallaşdırılmış əsas məlumat strukturları və onların praktiki ssenarilərə tətbiqi yer alır.

---

## Tapşırıqlar və İstifadə Olunan Məlumat Strukturları

### 1. Task 1: Mahnı Pleylisti İdarəetməsi (`task1_playlist.cpp`)
* **Məlumat strukturu:** Biristiqamətli Əlaqəli Siyahı (*Singly Linked List*)
* **Təsvir:** Mahnıların pleylistə ardıcıl əlavə edilməsi, pleylistin ekrana çıxarılması, mahnının ID üzrə axtarışı, müəyyən mahnının siyahıdan silinməsi, mahnı sayının hesablanması, növbəti mahnının oxunaraq siyahıdan çıxarılması və pleylistin tam təmizlənməsi funksiyaları reallaşdırılmışdır.

### 2. Task 2: Brauzer Tarixçəsi və "Geri" Düyməsi (`task2_browser_history.cpp`)
* **Məlumat strukturu:** Əlaqəli Siyahı əsaslı Yığın / Stek (*Linked List-based Stack* — LIFO: *Last In, First Out*)
* **Təsvir:** Veb brauzerdə ziyarət edilən səhifələrin tarixçəsinin idarə edilməsi. Yeni səhifəyə keçid (`push`), "Geri" (Back) düyməsi ilə əvvəlki səhifəyə qayıdış (`pop`), cari aktiv səhifənin göstərilməsi (`peek`), bütün tarixçənin nümayişi (`display`) və yığının təmizlənməsi əməliyyatları həyata keçirilmişdir.

### 3. Task 3: Hava Limanı Qeydiyyat Növbəsi (`task3_airport.cpp`)
* **Məlumat strukturu:** Əlaqəli Siyahı əsaslı Növbə (*Linked List-based Queue* — FIFO: *First In, First Out*)
* **Təsvir:** Hava limanında sərnişinlərin qeydiyyatdan (*check-in*) keçid prosesinin simulyasiyası. Sərnişinin növbənin sonuna daxil olması (`enqueue`), növbənin əvvəlindəki sərnişinin qeydiyyatdan keçərək növbədən çıxması (`dequeue`), növbəti sərnişinə baxış (`peek`) və növbənin ekranda əks olunması (`display`) funksionallıqları qurulmuşdur.

---

## Süni İntellekt (AI) Bəyannaməsi

* **ChatGPT İstifadəsi:** Stack, Queue və LinkedList məlumat strukturlarının real həyat nümunələrindəki iş prinsiplərini öyrənmək, həmçinin bu strukturları C++ dilində STL (*Standard Template Library*) istifadə etmədən, göstəricilər və qovşaq məntiqi ilə müstəqil şəkildə tətbiq etməyi mənimsəmək üçün ChatGPT-dən istifadə edilmişdir.
* **Antigravity Bəyannaməsi:** Bu `README.md` faylı **Antigravity** tərəfindən yaradılmış və tərtib edilmişdir.
