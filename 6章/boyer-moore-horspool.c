#include <stdio.h>
#define CHARS 256 // ASCII文字の数

// Boyer-Moore-Horspoolアルゴリズムのためのanchorずらし表を作成する関数
void make_bmh_table(long table[], char pattern[], long psize) {
    for (int i = 0; i < CHARS; i++) {
        table[i] = psize;
    }
    for (int i = 0; i < psize - 1; i++) {
        table[(unsigned char)pattern[i]] = psize - 1 - i;
    }
}

// 全照合成功数と位置を記録するためのグローバル変数
long matches = 0;
long mats[1024]; // 適切なサイズに設定

void report(char text[], long position) {
    printf("matched at text[%ld].\n", position);
    mats[matches] = position; // 照合成功位置を記録
    matches++; // 照合成功数をインクリメント
}

// パターンがテキスト内で一致する箇所を検索する関数
void bmh_match(char pattern[], long psize, char text[], long tsize) {
    long table[CHARS]; // text上の文字cに対する適切な anchorずらし量の表
    long pix, anchor, tix, comps = 0;
    char c;

    printf("pattern size = %ld, text size = %ld.\n", psize, tsize);
    make_bmh_table(table, pattern, psize); // 前処理：“anchorずらし表”の作成

    anchor = 0;
    while (anchor <= tsize - psize) {
        tix = anchor + psize - 1; // このラウンドのtext上の照合開始位置
        c = text[tix]; // このラウンドのtext上の照合開始文字

        for (pix = psize - 1; pix >= 0; pix--) { // patternの最後尾から先頭に向けて照合
            comps++;
            if (pattern[pix] != text[tix]) {
				break;
			}
            tix--;
        }

        if (pix < 0) {
            report(text, anchor); // 一致箇所の報告
        }

        anchor += table[(unsigned char)c]; // このラウンドのtext上の照合開始文字で決まる“ずらし量”
    }

    // プログラムの最後で照合成功数と位置を出力する
	printf("Total matches: %ld\n", matches);
	printf("Match positions: ");
	for (long i = 0; i < matches; i++) {
		printf("%ld ", mats[i]);
	}
	printf("\n");
}

int main() {
    char text[] = "genshin impact is great game";
    char pattern[] = "game";
    bmh_match(pattern, sizeof(pattern) - 1, text, sizeof(text) - 1);
    return 0;
}
