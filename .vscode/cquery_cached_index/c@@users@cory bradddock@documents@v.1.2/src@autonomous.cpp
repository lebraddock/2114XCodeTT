#include "main.h"
#include "includeStuff.h"
#include "chassisLib.h"
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


//arrays
/*
double blueRightArray[266] = {0.007985,0.015963,0.035933,0.063882,0.099815,0.143734,0.195638,0.255527,0.323401,0.39926,0.483105,0.574935,0.67475,0.78255,0.898336,1.022106,1.153862,1.293604,1.44133,1.597041,1.760738,1.93242,2.112087,2.29974,2.495377,2.699,2.910608,3.130201,3.35778,3.593343,3.836892,4.088426,4.347945,4.61545,4.890939,5.174414,5.465874,5.765319,6.07275,6.388166,6.711566,7.042953,7.382324,7.72968,8.085022,8.448349,8.819661,9.198958,9.586241,9.981509,10.384762,10.796,11.215223,11.642432,12.077626,12.520805,12.971969,13.431118,13.89426,14.357402,14.820544,15.283686,15.746828,16.20997,16.673112,17.136254,15.383411,13.165168,13.408017,13.642695,13.869012,14.086818,14.296015,14.49657,14.688525,14.869304,15.036564,15.19089,15.333018,15.463849,15.584465,15.69614,15.800352,15.898786,15.993337,16.086102,16.179368,16.27559,16.377361,16.487365,16.608331,16.742972,16.893915,17.06363,17.254356,17.468031,17.706223,17.970078,18.260274,18.577,18.919948,19.288324,19.680878,20.095954,20.531543,20.985356,21.454894,21.937523,22.430549,22.93128,23.437083,23.94544,24.453979,24.96051,25.463039,25.959783,26.449171,26.929843,27.400645,27.860613,28.308965,28.745084,29.168501,29.578883,29.976012,30.359777,30.730156,31.087201,31.431035,31.761831,32.079809,32.385228,32.67797,32.958331,33.227039,33.484435,33.730869,33.966695,34.192268,34.407941,34.614063,34.810973,34.998999,35.178459,35.349653,35.512861,35.668344,35.816337,35.957048,36.09065,36.217285,36.337052,36.450005,36.55615,36.655437,36.747757,36.832934,36.91072,36.980789,37.042733,37.096056,37.140167,37.174381,37.197914,37.209882,37.209302,37.195099,37.166107,37.121082,37.05871,36.977629,36.876441,36.753737,36.608122,36.438238,36.242798,36.020608,35.770601,35.491858,35.183638,34.84539,34.476775,34.077672,33.648183,33.188628,32.699539,32.181642,31.635843,31.0632,30.464897,29.842823,29.20394,28.55465,27.896336,27.230342,26.557957,25.880405,25.198833,24.5143,23.827783,23.140162,22.45223,21.76469,21.078157,20.393165,19.710169,19.02955,18.352209,17.683852,17.02948,16.389145,15.762855,15.150587,14.552285,13.967874,13.397256,12.840319,12.296941,11.76699,11.250327,10.746811,10.256297,9.778642,9.3137,8.861331,8.421395,7.993757,7.578285,7.174852,6.783336,6.40362,6.035592,5.679146,5.334181,5.000601,4.678317,4.367243,4.0673,3.778414,3.500516,3.233541,2.977429,2.732127,2.497581,2.273748,2.060583,1.858049,1.66611,1.484737,1.313899,1.153573,1.003736,0.86437,0.735457,0.616985,0.508939,0.411311,0.324093,0.247277,0.180859,0.124835,0.079202,0.043959,0.019104,0.004637,0};

double blueLeftArray[266] = {0.007985,0.015963,0.035933,0.063882,0.099815,0.143734,0.195638,0.255527,0.323401,0.39926,0.483105,0.574935,0.67475,0.78255,0.898336,1.022106,1.153862,1.293604,1.44133,1.597041,1.760738,1.93242,2.112087,2.29974,2.495377,2.699,2.910608,3.130201,3.35778,3.593343,3.836892,4.088426,4.347945,4.61545,4.890939,5.174414,5.465874,5.765319,6.07275,6.388166,6.711566,7.042953,7.382324,7.72968,8.085022,8.448349,8.819661,9.198958,9.586241,9.981509,10.384762,10.796,11.215223,11.642432,12.077626,12.520805,12.971969,13.431118,13.89426,14.357402,14.820544,15.283686,15.746828,16.20997,16.673112,17.136254,19.710282,22.95976,23.643178,24.334763,25.034709,25.743163,26.460223,27.185923,27.920219,28.657705,29.392736,30.124726,30.852942,31.576482,32.294264,33.005012,33.707251,34.399295,35.07925,35.745019,36.394315,37.024683,37.633534,38.218182,38.775898,39.303973,39.79978,40.26085,40.684943,41.070124,41.414825,41.717902,41.978676,42.196958,42.373057,42.507766,42.602334,42.658419,42.678027,42.663448,42.617178,42.54185,42.44016,42.314797,42.168392,42.003464,41.822382,41.627339,41.420325,41.203125,40.977308,40.744233,40.505056,40.260739,40.012065,39.759651,39.503964,39.245341,38.983996,38.720042,38.453501,38.18432,37.912378,37.6375,37.359468,37.078022,36.792424,36.502378,36.208012,35.908987,35.604951,35.29555,34.98043,34.659238,34.331625,33.997253,33.655791,33.306924,32.950351,32.585792,32.212986,31.831697,31.44172,31.042878,30.635032,30.218083,29.791975,29.356703,28.912317,28.458926,27.996707,27.525907,27.046852,26.55995,26.065699,25.564687,25.057601,24.545226,24.028445,23.50824,22.98569,22.461958,21.93829,21.415999,20.896448,20.381036,19.871172,19.368252,18.873632,18.388602,17.914354,17.451958,17.00233,16.566214,16.144159,15.736504,15.343371,14.964657,14.600043,14.248995,13.910787,13.584514,13.269116,12.963409,12.666361,12.378993,12.102031,11.834094,11.573836,11.319967,11.071264,10.826582,10.584857,10.345116,10.106477,9.868147,9.629425,9.389693,9.14842,8.905149,8.6595,8.411427,8.163211,7.916979,7.67268,7.430304,7.189876,6.951451,6.715106,6.480937,6.249056,6.019586,5.79266,5.568414,5.346993,5.128539,4.913196,4.70111,4.492422,4.28727,4.085791,3.888116,3.694373,3.504682,3.319162,3.137924,2.961075,2.788715,2.62094,2.45784,2.2995,2.145999,1.997411,1.853807,1.715249,1.581798,1.45351,1.330433,1.212616,1.1001,0.992924,0.891122,0.794727,0.703765,0.618263,0.538241,0.46372,0.394715,0.331241,0.27331,0.220932,0.174114,0.132865,0.097188,0.067087,0.042566,0.023626,0.010268,0.002492,0};
*/
double blueRightArray[268] = {0.007924,0.01581,0.035658,0.063392,0.099051,0.142633,0.194139,0.25357,0.320924,0.396203,0.479405,0.570532,0.669583,0.776557,0.891456,1.014279,1.145026,1.283697,1.430292,1.584811,1.747254,1.917621,2.095912,2.282128,2.476267,2.67833,2.888318,3.106229,3.332065,3.565825,3.807508,4.057116,4.314648,4.580103,4.853483,5.134787,5.424015,5.721167,6.026243,6.339244,6.660168,6.989016,7.325788,7.670485,8.023105,8.38365,8.752118,9.128511,9.512827,9.905068,10.305233,10.713322,11.129334,11.553271,11.985132,12.424917,12.872626,13.32826,13.791817,14.259336,14.726855,15.194374,15.661894,16.129413,16.596932,17.064451,16.163379,13.467,13.731185,13.987732,14.236408,14.477003,14.709344,14.933296,15.148782,15.353,15.543348,15.720179,15.883966,16.035312,16.174966,16.303834,16.422994,16.533709,16.637427,16.735794,16.830646,16.924009,17.018076,17.115195,17.217828,17.328519,17.449842,17.584344,17.734484,17.902565,18.090668,18.300584,18.533758,18.791238,19.073637,19.38111,19.713353,20.069609,20.4487,20.849067,21.268826,21.705826,22.157722,22.622037,23.096233,23.577766,24.064148,24.552986,25.042022,25.529161,26.012489,26.490286,26.961029,27.423393,27.876242,28.318623,28.749754,29.169007,29.575901,29.970078,30.351298,30.71942,31.07439,31.416229,31.745021,32.060907,32.36407,32.652656,32.926844,33.188953,33.439275,33.678118,33.905798,34.122632,34.328942,34.525044,34.711251,34.887867,35.055187,35.213491,35.363044,35.504097,35.636876,35.761587,35.878408,35.98749,36.088953,36.182878,36.26931,36.34825,36.419652,36.48342,36.539402,36.587385,36.627096,36.65819,36.680254,36.692799,36.695258,36.686989,36.667268,36.635295,36.590196,36.531025,36.456774,36.366378,36.258731,36.132696,35.987121,35.820857,35.632778,35.421801,35.186908,34.927164,34.641743,34.329941,33.991198,33.625107,33.231426,32.810087,32.361191,31.885013,31.381987,30.852705,30.297891,29.718395,29.118242,28.503976,27.879125,27.244815,26.602161,25.952253,25.296147,24.63485,23.969315,23.300436,22.629038,21.95588,21.28165,20.60697,19.932389,19.258395,18.588455,17.92834,17.280684,16.645665,16.023418,15.414034,14.817568,14.234045,13.663462,13.105796,12.561003,12.029025,11.509791,11.00322,10.509223,10.027705,9.558569,9.101712,8.657033,8.224429,7.803798,7.395038,6.998052,6.612743,6.239018,5.876788,5.525965,5.186469,4.858219,4.541141,4.235165,3.940223,3.656255,3.3832,3.121006,2.86962,2.628995,2.39909,2.179864,1.971281,1.773307,1.585914,1.409074,1.242764,1.086962,0.941649,0.806809,0.682429,0.568496,0.465,0.371934,0.289289,0.217062,0.155247,0.103842,0.062845,0.032254,0.012069,0.002289,0};

double blueLeftArray[268] =
{0.007924,0.01581,0.035658,0.063392,0.099051,0.142633,0.194139,0.25357,0.320924,0.396203,0.479405,0.570532,0.669583,0.776557,0.891456,1.014279,1.145026,1.283697,1.430292,1.584811,1.747254,1.917621,2.095912,2.282128,2.476267,2.67833,2.888318,3.106229,3.332065,3.565825,3.807508,4.057116,4.314648,4.580103,4.853483,5.134787,5.424015,5.721167,6.026243,6.339244,6.660168,6.989016,7.325788,7.670485,8.023105,8.38365,8.752118,9.128511,9.512827,9.905068,10.305233,10.713322,11.129334,11.553271,11.985132,12.424917,12.872626,13.32826,13.791817,14.259336,14.726855,15.194374,15.661894,16.129413,16.596932,17.064451,18.791953,22.531852,23.202691,23.881165,24.567509,25.261931,25.964607,26.675668,27.395193,28.118059,28.838945,29.557497,30.273241,30.985576,31.693753,32.396864,33.093832,33.783395,34.464104,35.134314,35.792188,36.435703,37.062664,37.670725,38.257425,38.820219,39.356536,39.863828,40.339639,40.781665,41.187828,41.556336,41.885745,42.175007,42.423512,42.631103,42.798085,42.925213,43.013667,43.065004,43.081108,43.064129,43.01641,42.940429,42.838723,42.713833,42.568248,42.404359,42.224425,42.030539,41.824614,41.608371,41.383331,41.150821,40.911974,40.667744,40.418914,40.16611,39.909815,39.650385,39.388061,39.122984,38.855209,38.584714,38.311415,38.035172,37.7558,37.470718,37.179744,36.885001,36.586193,36.283014,35.975149,35.662279,35.344084,35.020247,34.690455,34.354405,34.011801,33.662364,33.305827,32.941942,32.57048,32.191238,31.804035,31.408722,31.005179,30.593325,30.173114,29.744545,29.307665,28.862569,28.409411,27.948402,27.479816,27.003998,26.521362,26.032395,25.537666,25.037816,24.53357,24.025727,23.515163,23.002823,22.489716,21.976906,21.4655,20.956637,20.451467,19.95114,19.456782,18.969476,18.490242,18.020013,17.559616,17.109755,16.670991,16.24373,15.828213,15.424511,15.032519,14.651965,14.282412,13.92327,13.573813,13.233192,12.901819,12.581074,12.270913,11.970212,11.677855,11.39275,11.113844,10.840127,10.570646,10.30451,10.040891,9.779031,9.518241,9.257901,8.997459,8.736431,8.475785,8.217675,7.962953,7.71144,7.463003,7.217551,6.975027,6.735408,6.498696,6.264914,6.034107,5.806333,5.581662,5.360176,5.141964,4.92712,4.715742,4.507933,4.303793,4.103427,3.906936,3.714421,3.525981,3.341711,3.161705,2.986053,2.814841,2.648151,2.486063,2.32865,2.175984,2.028131,1.885153,1.747109,1.614054,1.486038,1.363108,1.245307,1.132675,1.025249,0.923061,0.826141,0.734515,0.648208,0.567241,0.491633,0.4214,0.356555,0.297111,0.243078,0.194464,0.151277,0.11352,0.081198,0.054315,0.032873,0.016872,0.006313,0.001197,0};

double skillsRightArray[546] =
{0.005952,0.003805,0.00856,0.026067,0.050623,0.072892,0.099205,0.129558,0.163946,0.202364,0.244803,0.291253,0.341704,0.396141,0.454549,0.516909,0.583201,0.6534,0.72748,0.80541,0.887156,0.972681,1.061944,1.154898,1.251494,1.351677,1.455387,1.562559,1.673122,1.787,1.904109,2.02436,2.147658,2.273897,2.402968,2.53475,2.669116,2.805928,2.945041,3.086299,3.229534,3.37457,3.521219,3.66928,3.818542,3.968781,4.119759,4.271226,4.42292,4.574564,4.725869,4.876534,5.026244,5.174675,5.321491,5.46635,5.608903,5.748797,5.885681,6.01921,6.147405,6.26841,6.382108,6.488428,6.58736,6.678961,6.76337,6.840823,6.911665,6.976368,7.035546,7.089971,7.140592,7.188548,7.235182,7.282051,7.330933,7.383828,7.442948,7.510707,7.589695,7.682642,7.792375,7.921764,8.072428,8.245859,8.444525,8.670563,8.925698,9.211183,9.527751,9.875584,10.25431,10.663014,11.10028,11.564239,12.052644,12.562946,13.092378,13.638041,14.196985,14.766282,15.343089,15.924702,16.508596,17.092458,17.674199,18.251973,18.82417,19.389416,19.946562,20.494671,21.033001,21.56099,22.078238,22.584487,23.07961,23.563591,24.036511,24.498538,24.949912,25.390938,25.821974,26.243427,26.655743,27.059404,27.454925,27.842846,28.223735,28.59818,28.966794,29.330208,29.689073,30.04406,30.39586,30.745179,31.092747,31.439306,31.785618,32.13246,32.480623,32.830905,33.184113,33.541051,33.9059,34.28301,34.673451,35.078279,35.49851,35.93511,36.388956,36.860808,37.351263,37.860702,38.389227,38.936585,39.502087,40.084508,40.681991,41.291934,41.910894,42.534491,43.157344,43.773036,44.374145,44.95233,45.498513,46.00314,46.456542,46.849368,47.173066,47.420376,47.585787,47.665903,47.659673,47.568467,47.395973,47.147942,46.831801,46.456194,46.030492,45.564317,45.067127,44.547878,44.01477,43.475095,42.935154,42.400238,41.874671,41.361876,40.864467,40.384352,39.922835,39.480715,39.058379,38.655881,33.638519,32.945966,32.901115,32.85564,32.809575,32.762953,32.715806,32.668164,32.620059,32.571519,32.522574,32.473252,32.42358,32.373584,32.323289,32.272719,32.221898,32.170847,32.119589,32.068142,32.016527,31.964761,31.912861,31.860845,31.808726,31.75652,31.704239,31.651895,31.599502,31.547067,31.494603,31.442117,31.389617,31.337111,31.284605,31.232106,31.179617,31.127145,31.074691,31.02226,30.969854,30.917476,30.865126,30.812805,30.760515,30.708255,30.656025,30.603825,30.551652,30.499507,30.447386,30.395289,30.343213,30.291156,30.239116,30.187088,30.135072,30.083063,30.03106,29.979058,29.927054,29.875047,29.823032,29.771007,29.718969,29.666915,29.614842,29.562749,29.510633,29.458492,29.406324,29.354128,29.301904,29.249649,29.197364,29.145048,29.092703,29.040329,28.987927,28.9355,28.883049,28.830579,28.778092,28.725592,28.673086,28.620578,28.568075,28.515584,28.463113,28.410671,28.358266,28.305911,28.253615,28.201391,28.149252,28.097213,28.045287,27.993492,27.941844,27.890361,27.839062,27.787967,27.737097,27.686474,27.636121,27.586062,27.536322,27.486928,27.437905,27.389282,27.341087,27.29335,33.806401,34.451904,34.510746,34.569357,34.627648,34.685528,34.742898,34.799659,34.855704,34.910924,34.965207,35.018437,35.070494,35.121257,35.170602,35.218404,35.264535,35.308869,35.351278,35.391635,35.429814,35.465693,35.499151,35.53007,35.558337,35.583845,35.606491,35.62618,35.642822,35.656337,35.666652,35.673704,35.677439,35.677812,35.67479,35.668349,35.658477,35.645172,35.628443,35.608309,35.584802,35.557961,35.527838,35.494492,35.457994,35.418421,35.375858,35.3304,35.282145,35.2312,35.177676,35.121686,35.06335,35.00279,34.94013,34.875493,34.809007,34.740796,34.670985,34.5997,34.527061,34.453189,34.378201,34.302212,34.225331,34.147665,34.069318,33.990389,33.91097,33.831153,33.751022,33.670657,33.590134,33.509524,33.428893,33.348302,33.267808,33.187464,33.107318,33.027414,32.94779,32.868484,32.789527,32.710946,32.632768,32.555012,32.477697,32.400839,32.324449,32.248538,32.173111,32.098173,32.023727,31.947203,31.865463,31.777964,31.684755,31.585884,31.481399,31.371342,31.255754,31.134676,31.008144,30.876193,30.738858,30.596172,30.448164,30.294865,30.136304,29.972508,29.803505,29.629319,29.449977,29.265504,29.075924,28.881262,28.68154,28.476784,28.267017,28.052262,27.832544,27.607885,27.378311,27.143846,26.904513,26.660338,26.411346,26.157562,25.899012,25.635721,25.367717,25.095025,24.817673,24.535688,24.249097,23.957927,23.662208,23.361966,23.057229,22.748026,22.434384,22.11633,21.793893,21.467099,21.135975,20.800547,20.460841,20.116882,19.768694,19.4163,19.059722,18.698982,18.334099,17.967375,17.601621,17.23735,16.874543,16.51318,16.153241,15.794706,15.437555,15.081767,14.72732,14.374194,14.022365,13.671812,13.322511,12.974439,12.627571,12.281884,11.937352,11.593951,11.251653,10.910433,10.570263,10.231118,9.892968,9.557999,9.228899,8.906134,8.589655,8.279418,7.975379,7.677492,7.385718,7.100014,6.820343,6.546666,6.278946,6.017148,5.761238,5.511183,5.266953,5.028516,4.795844,4.568909,4.347685,4.132146,3.922269,3.718029,3.519406,3.326379,3.138927,2.957033,2.780678,2.609847,2.444523,2.284692,2.130341,1.981456,1.838025,1.700037,1.567483,1.440351,1.318635,1.202325,1.091415,0.985896,0.885765,0.791014,0.70164,0.617637,0.539002,0.465731,0.397822,0.335271,0.278078,0.226239,0.179754,0.138622,0.10284,0.07241,0.047329,0.027599,0.013217,0.004186,0.000504,0};

double skillsLeftArray[546] =
{0.005952,0.003805,0.00856,0.056505,0.098187,0.141394,0.192462,0.251395,0.318197,0.392874,0.475436,0.56589,0.664249,0.770526,0.884737,1.0069,1.137037,1.275171,1.42133,1.575543,1.737844,1.908271,2.086866,2.273673,2.468744,2.672132,2.883898,3.104107,3.33283,3.570143,3.816128,4.070877,4.334484,4.607053,4.888697,5.179533,5.479691,5.789306,6.108526,6.437506,6.776413,7.125423,7.484726,7.854521,8.235019,8.626446,9.029037,9.443044,9.868729,10.306368,10.75625,11.218677,11.693962,12.182431,12.684419,13.200269,13.730328,14.27495,14.834486,15.409281,15.99536,16.588628,17.189203,17.797153,18.41249,19.035157,19.665013,20.301824,20.945243,21.594799,22.249878,22.909707,23.573339,24.239632,24.907246,25.574621,26.239981,26.901327,27.556446,28.202924,28.838172,29.459461,30.063963,30.648811,31.206433,31.729387,32.215205,32.661751,33.067301,33.430603,33.750923,34.028081,34.262448,34.454939,34.606971,34.720412,34.797508,34.840808,34.853078,34.837216,34.796172,34.732873,34.65016,34.550739,34.437131,34.311652,34.176386,34.033184,33.883651,33.729164,33.57087,33.409706,33.246414,33.081556,32.915533,32.748601,32.580889,32.412412,32.243088,32.072752,31.901161,31.728011,31.552945,31.375556,31.195397,31.011986,30.824809,30.633325,30.436967,30.235146,30.02725,29.812649,29.590689,29.3607,29.121993,28.873859,28.615571,28.346384,28.065537,27.772253,27.465741,27.145202,26.80983,26.45882,26.093943,25.716802,25.326324,24.921456,24.501179,24.064528,23.610625,23.138708,22.648181,22.138662,21.610049,21.062594,20.496985,19.914446,19.316836,18.706755,18.087647,17.463893,16.840877,16.225014,15.623731,15.045371,14.499017,13.994227,13.540673,13.147713,12.823901,12.576503,12.411032,12.330888,12.33712,12.428359,12.600915,12.849034,13.165286,13.541021,13.966865,14.433192,14.930538,15.449947,15.983211,16.523038,17.063126,17.598181,18.123879,18.636797,19.134319,19.614539,20.076153,20.518361,20.940778,21.343349,26.293742,27.053945,27.098799,27.144276,27.190343,27.236968,27.284118,27.331763,27.379871,27.428413,27.47736,27.526685,27.576359,27.626358,27.676656,27.727228,27.778052,27.829104,27.880365,27.931814,27.983432,28.0352,28.087101,28.13912,28.19124,28.243449,28.295731,28.348076,28.400472,28.452908,28.505374,28.557862,28.610363,28.662871,28.715378,28.767879,28.820368,28.872842,28.925297,28.977729,29.030136,29.082516,29.134867,29.187188,29.239479,29.29174,29.34397,29.396172,29.448345,29.500491,29.552612,29.604709,29.656785,29.708843,29.760884,29.812911,29.864928,29.916937,29.96894,30.020942,30.072946,30.124953,30.176968,30.228993,30.281031,30.333084,30.385156,30.437249,30.489365,30.541505,30.593672,30.645867,30.698091,30.750346,30.80263,30.854944,30.907289,30.959662,31.012063,31.064489,31.116938,31.169407,31.221893,31.274391,31.326896,31.379402,31.431904,31.484393,31.536862,31.589303,31.641706,31.69406,31.746354,31.798576,31.850713,31.90275,31.954674,32.006467,32.058113,32.109594,32.16089,32.211983,32.262851,32.313471,32.363822,32.413878,32.463615,32.513007,32.562028,32.610648,32.658841,32.706575,26.073961,25.547892,25.489045,25.430428,25.372131,25.314246,25.25687,25.200104,25.144054,25.088828,25.034539,24.981304,24.929242,24.878473,24.829123,24.781316,24.73518,24.690841,24.648428,24.608067,24.569883,24.534,24.500538,24.469616,24.441345,24.415834,24.393186,24.373495,24.356851,24.343334,24.333018,24.325965,24.32223,24.321857,24.324879,24.33132,24.341194,24.3545,24.371231,24.391367,24.414878,24.441721,24.471848,24.505197,24.5417,24.581278,24.623845,24.669308,24.717568,24.768518,24.822049,24.878044,24.936386,24.996952,25.059619,25.124262,25.190756,25.258973,25.32879,25.400083,25.472728,25.546607,25.621602,25.697598,25.774486,25.852158,25.930511,26.009448,26.088872,26.168696,26.248833,26.329204,26.409733,26.490349,26.570986,26.651583,26.732082,26.812431,26.892583,26.972492,27.05212,27.131431,27.210393,27.288978,27.367161,27.444921,27.52224,27.599102,27.675495,27.751411,27.826841,27.901782,27.976231,28.047927,28.114054,28.174037,28.227824,28.275367,28.316621,28.351541,28.380087,28.40222,28.417901,28.427095,28.429769,28.42589,28.415426,28.39835,28.37463,28.344241,28.307154,28.263345,28.212786,28.155455,28.091325,28.020373,27.942575,27.857907,27.766345,27.667866,27.562446,27.45006,27.330686,27.204298,27.070873,26.930385,26.78281,26.628121,26.466294,26.297303,26.121121,25.937721,25.747076,25.549161,25.343946,25.131404,24.911508,24.68423,24.449542,24.207415,23.957823,23.700737,23.436131,23.163976,22.884246,22.596916,22.301959,21.99935,21.689066,21.371083,21.045379,20.711933,20.370724,20.024284,19.675751,19.325737,18.974258,18.621336,18.26699,17.911239,17.554104,17.195607,16.835768,16.474609,16.112152,15.748419,15.383435,15.017222,14.649804,14.281205,13.911452,13.540568,13.16858,12.795515,12.421399,12.046259,11.670123,11.295638,10.926067,10.562067,10.203685,9.850965,9.503954,9.162693,8.827226,8.497592,8.173831,7.855981,7.544078,7.238158,6.938254,6.6444,6.356627,6.074965,5.799442,5.530087,5.266927,5.009985,4.759288,4.514857,4.276714,4.04488,3.819376,3.600218,3.387426,3.181015,2.981002,2.7874,2.600224,2.419486,2.245199,2.077373,1.916019,1.761146,1.612763,1.470879,1.3355,1.206633,1.084284,0.96846,0.859164,0.756401,0.660175,0.570489,0.487347,0.41075,0.340702,0.277203,0.220255,0.16986,0.126019,0.088731,0.057998,0.03382,0.016197,0.00513,0.000617,0};

void followSkillsPath()
{
  int i = 0;
  int startTime = pros::millis();
  int targetTime = pros::millis() + (546 * 10);
  drive.resetLeftEncoder();
  drive.resetRightEncoder();
  while(pros::millis() < targetTime)
  {
    i = (pros::millis() - startTime) / 10;
    drive.setLeftVelocity(  (skillsLeftArray[i] + skillsLeftArray[i+1]) / 2);
    drive.setRightVelocity( (skillsRightArray[i] + skillsRightArray[i+1]) / 2);
    pros::delay(10);
  }
  drive.stopDriveVelocity();
}


void Align()
{
  double akp = .08;
  double aki = .0006;
  double aerror;
  double atotalError;
  int sign;
  int lastSign = 0;
  double apower;
  int timeOut = pros::millis() + 1000;
  while(pros::millis() < timeOut)
  {
    aerror = leftUltra.get_value() - rightUltra.get_value();
    atotalError += aerror;
    apower = aerror * akp + atotalError * aki;
    sign = signchk(aerror);
    if(sign != lastSign)
      atotalError = 0;


    drive.setLeftVelocity( -1 * apower);
    drive.setRightVelocity(apower);
    lastSign = sign;
    pros::delay(20);
  }
  drive.setLeftVelocity(0);
  drive.setRightVelocity(0);
}
double theta = 0;
void angleCalc (void * param)
{
  double lastLeft = 0;
  double lastRight = 0;
  double dtheta = 0;

  double chassisWidth = 9.8634;
  while(true)
  {

    dtheta = ((drive.getLeftVelocity()  * .01) - (drive.getRightVelocity() * .01)) / chassisWidth;
    theta = theta + dtheta;
    pros::lcd::print(6, "pos : %f", theta / 6.28 * 360);
    pros::delay(10);
  }
}

void alignAngle(double num)
{
  num = num / 360 * 2 * 3.1415;
  double akp = 4;
  double aki = .03;
  int sign = 0;
  int lastSign;
  double aerror;
  double apower;
  double atotalError = 0;
  int timeOut = pros::millis() + 1000;
  while(pros::millis() < timeOut)
  {
    aerror = num - theta;
    atotalError += aerror;
    apower = aerror * akp + atotalError * aki;
    sign = signchk(aerror);
    if(sign != lastSign)
      atotalError = 0;

    drive.setLeftVelocity(apower);
    drive.setRightVelocity( -1 * apower);
    lastSign = sign;
    pros::delay(20);
  }
  drive.setLeftVelocity(0);
  drive.setRightVelocity(0);
}




void followBluePath()
{
  int i = 0;
  int startTime = pros::millis();
  int targetTime = pros::millis() + (268 * 10);
  drive.resetLeftEncoder();
  drive.resetRightEncoder();
  while(pros::millis() < targetTime)
  {
    i = (pros::millis() - startTime) / 10;
    drive.setLeftVelocity(-1 * (blueLeftArray[i] + blueLeftArray[i+1]) / 2);
    drive.setRightVelocity(-1 * (blueRightArray[i] + blueRightArray[i+1]) / 2);
    pros::delay(10);
  }
  drive.stopDriveVelocity();
}
void followRedPath()
{
  int i = 0;
  int startTime = pros::millis();
  int targetTime = pros::millis() + (268 * 10);
  drive.resetLeftEncoder();
  drive.resetRightEncoder();
  while(pros::millis() < targetTime)
  {
    i = (pros::millis() - startTime) / 10;
    drive.setRightVelocity(-1 * (blueLeftArray[i] + blueLeftArray[i+1]) / 2);
    drive.setLeftVelocity(-1 * (blueRightArray[i] + blueRightArray[i+1]) / 2);
    pros::delay(10);
  }
  drive.stopDriveVelocity();
}

void liftHigh()
{
  liftDown = false;
  pros::delay(50);
  if(isCube() == true)
    intakeThing();
  lift.move_absolute(highTower, 100);

}

void liftMed()
{
  liftDown = false;
  pros::delay(50);
  if(isCube() == true)
    intakeThing();
  lift.move_absolute(lowTower, 100);

}
void liftLow()
{
  while(liftSense.get_value() != 1)
  {
    lift.move(-120);
  }
  lift.move(-12);
  liftDown = true;
  lift.tare_position();
}

 void trayToggle()
 {
   if(tray == true)
   {
     ttarget = finalPos;
     tray = false;
   }
   else
   {
     ttarget = startPos;
     tray = true;
   }
 }

 void trayControl(void * param)
 {
   int terror;
   int ttotalError = 0;
   int tpower;
   int tsign = 1;
   int tlastSign = 1;


   while(true)
   {
     if(liftDown == true && pros::competition::is_autonomous())
     {
       if(liftSense.get_value() == 0)
        lift.move(-127);
     }
   //tilter pi loop
   terror = ttarget - tilter.get_position();
   ttotalError += terror;
  // if(ttotalError > 12000)
  //   ttotalError = 12000;
   tsign = signchk(terror);
   if(tsign != tlastSign)
     ttotalError = 0;
   tlastSign = tsign;
   tpower = terror * atkp + atki * ttotalError;
   if(terror > 220)
     tpower = 127;
     if(pros::competition::is_autonomous())
      tilter.move(tpower);
   pros::delay(20);
  // pros::lcd::print(7, "pos : %d", leftUltra.get_value());
  // pros::lcd::print(6, "pos : %d", rightUltra.get_value());
    }
 }


void setIntake(int v)
{
  intake1.move(v);
  intake2.move(v);
}

void deploy()
{
  setIntake(-127);
  pros::delay(13);
  ttarget = finalPos;
  setIntake(0);

    pros::delay(1300);
    setIntake(30);
    pros::delay(300);
    setIntake(0);
    pros::delay(1000);
    setIntake(127);
    pros::delay(200);
    setIntake(0);
  ttarget = startPos;

  pros::delay(170);
}
void deploy2()
{
  setIntake(-127);
  pros::delay(13);
  ttarget = finalPos;
  setIntake(0);

    pros::delay(600); //1500
    setIntake(-60);
    pros::delay(250);
    setIntake(20);
    pros::delay(150);
    setIntake(0);
    pros::delay(500);
  ttarget = startPos;

  pros::delay(170);
}

void redStack()
{
  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
  liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
  pros::delay(150);
  liftLow();
  setIntake(127);
  pros::delay(50);
  drive.stopDriveMotors();
  drive.driveForward(43,30,50);
  setIntake(0);
  followRedPath();
  setIntake(127);
  drive.driveForward(38, 25, 45);
  int timeOut = pros::millis() + 700;
  while(isIntake() && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(0);
  drive.turnRight(147, 25, 25);
  setIntake(0);
  intake1.move_velocity(-70);
  intake2.move_velocity(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  // gamers rize up!!!!!
  pros::delay(20);
  setIntake(0);
  ttarget = midPos;
  drive.driveForward(48, 40, 50);

  setIntake(0);
  intake1.move_velocity(-70);
  intake2.move_velocity(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  pros::delay(50);
  setIntake(0);
  deploy2();
  setIntake(-90);
  drive.driveBackward(24, 50, 100);
}

void redCollect()
{
  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
  liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
}

void blueStack()
{

  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
  liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
  pros::delay(150);
  liftLow();
  setIntake(127);
  pros::delay(50);
  drive.stopDriveMotors();
  drive.driveForward(43,30,50);
  setIntake(0);
  followBluePath();
  setIntake(127);
  drive.driveForward(38, 25, 45);
  int timeOut = pros::millis() + 700;
  while(isIntake() && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(0);
  drive.turnLeft(147, 25, 25);
  setIntake(0);
  intake1.move_velocity(-70);
  intake2.move_velocity(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  // gamers rize up!!!!!
  pros::delay(20);
  setIntake(0);
  ttarget = midPos;
  drive.driveForward(48, 40, 50);

  setIntake(0);
  intake1.move_velocity(-70);
  intake2.move_velocity(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  pros::delay(50);
  setIntake(0);
  deploy2();
  setIntake(-90);
  drive.driveBackward(24, 50, 100);

}

void blueCollect()
{
  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
  liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
}

void skills()
{

  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
    liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
  pros::delay(300);
  setIntake(127);
  pros::delay(150);
  drive.stopDriveMotors();
  setIntake(127);
  drive.driveForward(42, 24, 35);
  pros::delay(350);
  setIntake(0);
  pros::delay(200);
  liftMed();
  pros::delay(400);
  drive.turnRight(24, 25, 30);

  pros::delay(400);
  drive.driveForward(8, 10, 20);
  setIntake(-90);
  pros::delay(500);
  int timeOut;
  setIntake(0);
  drive.driveBackward(10, 25, 30);
  liftLow();
  pros::delay(500);
  drive.turnLeft(147, 20, 40);
  liftMed();
  pros::delay(500);
  drive.driveForward(12, 20, 30);
  setIntake(-80);
  pros::delay(500);
  setIntake(0);
  drive.driveBackward(9, 20, 30);
  pros::delay(400);

  drive.turnRight(128,30,50);
  liftLow();
  setIntake(127);
  drive.driveForward(65,20,25);
  setIntake(0);

  pros::delay(300);

  liftMed();
  pros::delay(500);
  drive.turnLeft(111, 10, 20);
  drive.driveForward(7, 10, 20);
  setIntake(-70);
  pros::delay(1000);
  setIntake(0);
  drive.driveBackward(12, 30, 50);
  drive.turnRight(52,30, 40);
  liftLow();
  pros::delay(300);
  setIntake(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(0);
  drive.driveForward(27, 30, 50);
  deploy();
  setIntake(-100);
  drive.driveBackward(9, 30, 70);



  drive.turnRight(150,30,30);
  drive.driveBackward(24, 30, 50);
  pros::delay(100);

  intake1.move(127);
  intake2.move(127);
  drive.driveForward(46, 30, 40);
  drive.driveBackward(10, 20,30);
  drive.driveForward(5, 10, 20);
  drive.driveBackward(5, 10, 20);
  setIntake(-90);

  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  pros::delay(30);
  setIntake(0);


  liftHigh();
  drive.driveForward(15, 12, 20);
  setIntake(-75);
  pros::delay(400);
  drive.driveBackward(25,35,40);



liftLow();
setIntake(0);
followSkillsPath();
setIntake(0);
drive.turnLeft(130, 15,20);
drive.driveBackward(95, 35, 60);
drive.driveForward(20, 40, 70);
}




void autonomous()
{
  pros::Task angle (trayControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                TASK_STACK_DEPTH_DEFAULT, "Tary");

 pros::Task angleCalculation (angleCalc, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "on jah");
                drive.resetLeftEncoder();
                drive.resetRightEncoder();




             //drive.turnLeft(90, 35, 40);
  if(autoNum == 1)
    redStack();
  if(autoNum == 2)
    redCollect();
  if(autoNum == 3)
    blueStack();
  if(autoNum == 4)
    blueCollect();
  if(autoNum == 5)
    skills();



}
