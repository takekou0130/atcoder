// てきとうにデータをjsonで管理
const baseData = [
  {
    /** 名前 */
    name: "a",
    /** 評価パラメータ */
    params: {
      /** 入社n年目 */
      year: 0,
      /** 中途か */
      career: 0,
      /** メンター */
      mentor: 0,
      /** 6月のチーム(A=0, B=1) */
      juneTeam: 0,
      /** 去年井戸端いたか */
      lastYearMember: 0,
      /** 所属G */
      group: 0,
      /** SM経験 */
      scrumMaster: 0,
    },
  },
  {
    name: "b",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
  {
    name: "c",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
  {
    name: "d",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
  {
    name: "e",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
  {
    name: "f",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
  {
    name: "g",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
  {
    name: "h",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
  {
    name: "i",
    params: {
      year: 0,
      career: 0,
      mentor: 0,
      juneTeam: 0,
      lastYearMember: 0,
      group: 0,
      scrumMaster: 0,
    },
  },
];

const calcRange = (baseData) => {
  const paramKeys = Object.keys(baseData[0].params);
  const memberNum = baseData.length;
  const range = [];
  for (let i = 0; i < paramKeys.length; i++) {
    let min = 10000;
    let max = 0;
    for (let j = 0; j < memberNum; j++) {
      const now = baseData[j].params[paramKeys[i]];
      if (now < min) min = now;
      if (now > max) max = now;
    }
    range.push([max, min]);
  }

  return range;
};

const normalize = (baseData, range) => {
  const memberNum = baseData.length;
  const norm = [];
  for (let i = 0; i < memberNum; i++) {
    const res = [];
    const paramVal = Object.values(baseData[i].params);
    for (let j = 0; j < paramVal.length; j++) {
      // オブジェクトなのでparamとrangeの順番の対応が保証されてない気がするが許してほしい
      const cal = (paramVal[j] - range[j][1]) / (range[j][0] - range[j][1]);
      if (isNaN(cal) || !isFinite(cal)) res.push(0);
      else res.push(cal);
    }
    // 乱数を入れる
    res.push(Math.random());
    norm.push(res);
  }
  return norm;
};

const dfs = (depth, prev, max, len) => {
  if (depth === len) {
    const teamA = [];
    const teamB = [];
    // 乱数を入れた分で+1
    const paramLen = Object.values(baseData[0].params).length + 1;
    // 初期化
    for (let i = 0; i < paramLen; i++) {
      teamA.push(0);
      teamB.push(0);
    }

    // AとBにそれぞれ値を追加
    for (let i = 0; i < max + 1; i++) {
      if (combi.includes(i)) {
        for (let j = 0; j < paramLen; j++) {
          teamA[j] += calcData[i][j];
        }
      } else {
        for (let j = 0; j < paramLen; j++) {
          teamB[j] += calcData[i][j];
        }
      }
    }

    // 両者の差を計算
    let abs = 0;
    for (let i = 0; i < paramLen; i++) {
      abs += Math.abs(teamA[i] - teamB[i]);
    }
    // 差が最小のときに記録する
    if (absMin > abs) {
      absMin = abs;
      for (let i = 0; i < len; i++) {
        bestCombi[i] = combi[i];
      }
    }
    return;
  } else {
    for (let i = prev; i <= max; i++) {
      combi[depth] = i;
      dfs(depth + 1, i + 1, max, len);
    }
  }
};

const output = (combi, data) => {
  const teamAName = [];
  const teamBName = [];
  for (let i = 0; i < data.length; i++) {
    if (combi.includes(i)) {
      teamAName.push(data[i].name);
    } else {
      teamBName.push(data[i].name);
    }
  }
  console.log("teamA:", teamAName);
  console.log("teamB:", teamBName);
};

// paramのrangeを求める
const range = calcRange(baseData);
// 正規化しつつ最後に乱数をpush
const calcData = normalize(baseData, range);
console.log(calcData);

const combi = [];
const bestCombi = [];
let absMin = 10000;
const half = Math.floor(baseData.length / 2);
// 組み合わせを探索(これがやりたかった)
dfs(0, 0, baseData.length - 1, half);
console.log(bestCombi);

output(bestCombi, baseData);
