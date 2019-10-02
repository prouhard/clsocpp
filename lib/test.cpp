/********************************************************************************************************
 ********************************************************************************************************
 ** This file is temporary and is just there to store the test data for debugging / profiling purposes **
 ********************************************************************************************************
 ********************************************************************************************************/

#include "test.h"


VectorXd getB()
{
    VectorXd b(19);
    b << -1.0,
         -1.0,
         0.015621478921797374,
         0.05354380063362084,
         0.05409772070789842,
         0.0443288257925233,
         0.03707338340868491,
         0.05831476940161874,
         0.0,
         0.028251985275000002,
         0.02177732015704552,
         0.009164280358195288,
         0.057089279213852734,
         0.052487207560942606,
         0.05378209381131514,
         -0.01089797,
         0.042021486010623846,
         0.07751153555,
         0.013988864460000002
    ;
    return b;
}


VectorXd getC()
{
    VectorXd c(94);
    c << -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.14285714285714285,
         -0.07142857142857142,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         -0.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         0.0,
         0.0,
         1.0,
         -1.0,
         3.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.2,
         0.2,
         -9.629175027945307e-14,
         2.968629146227936e-06,
         -0.0031585943953099252,
         -0.0002953526794276605,
         0.00022608977236580018,
         0.0005143328595760771,
         -0.003641913400641216,
         0.015450460759197983,
         -0.01596516325929064,
         -0.0006921285891325203,
         -0.0050323842551783906,
         -0.0059099074667084564,
         0.04200379126183474,
         -0.013427571228608805,
         -0.00013200351150770154,
         -0.010875628799653581,
         -0.0613115638362327,
         0.04,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0,
         0.0
    ;
    return c;
}


std::vector<std::size_t> getConstraintsLengths()
{
    std::vector<std::size_t> constraints_lengths = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 19, 19, 19
    };
    return constraints_lengths; 
}


MatrixXd getM()
{
    MatrixXd M(94, 19);
    M << 0.0,0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-1.0,
         0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,
         0.0,0.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,
         0.0,0.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,
         0.0,0.0,4.0,6.0,6.0,5.0,5.0,5.0,1.0,4.0,4.0,4.0,5.0,5.0,5.0,2.0,5.0,6.0,3.0,
         -1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.00015409275244888056,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.00015918259955158417,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.009463056451274082,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.013529605664800014,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.016250771667737307,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.018937022019928317,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.022445968169812806,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.025909334310728508,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.02938362727057488,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.03137736344945668,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.03291702533156552,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.03421285667158934,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.03638091375149979,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.03659987490090539,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.036879599269137475,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.037452195356965874,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,
         0.0,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.04145965862618746,-0.0,
         0.0,-1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,3.2424060229505787e-14,3.6695000654855055e-21,2.5230599649427367e-21,2.4514561573927958e-14,5.161115932959659e-15,8.017992380179785e-22,4.057877129021447e-06,4.162706932019305e-13,2.8183318387089667e-15,6.635176089465661e-22,1.1479457688590708e-14,9.56745395501627e-15,1.7500163531486604e-14,-4.191905552720825e-06,-1.3894953768130532e-13,-1.9739386209841657e-13,-1.0137658981025477e-13,
         0.0,0.0,-9.988291756133604e-07,-9.19776105453074e-09,-1.2260239821751775e-08,-7.560609098251058e-07,-1.5803937765858105e-07,-2.6806083444720386e-09,-0.001299095666496014,-1.2809413782752801e-05,-9.289669095334976e-08,-5.319977007838177e-09,-3.520867355363018e-07,-2.9893952836821537e-07,-5.393325455984697e-07,-0.0012575594880899661,4.278327526064011e-06,6.103063091253755e-06,3.1203719939928007e-06,
         0.0,0.0,-0.00028151033496769714,0.005290792080295329,0.0078336646654851,6.759595948799258e-05,-0.00012312548965965234,0.0012588518523003185,-4.6576931963297526e-05,0.00019770259691043627,0.0037035881167892144,0.0038442247405719365,-4.4543186360563934e-05,0.0027507747182526467,-1.56262155002136e-05,-4.508681783742105e-05,-0.0002616624167729482,-0.018494829703452818,0.00012211779983257098,
         0.0,0.0,-0.00017710987568592934,0.0029527046986515563,0.00809902427594528,3.09478015407612e-05,-5.406875654523573e-05,0.0003985564354305003,-5.228860163629084e-06,3.4615373783464006e-05,0.002226839993266433,-0.03334504310280618,-5.6280583447441026e-05,0.0011156856015990362,-9.386029187305902e-06,-5.06157523958853e-06,-9.932397181113632e-05,-0.0020110920538882284,9.221102762700339e-05,
         0.0,0.0,0.001105981573949674,-0.018652852934588234,0.0296403317119771,-0.0001081067735230036,0.0002380607781723269,-0.001056281913740092,8.23079260064832e-06,0.00013329418910697444,-0.019222098742215595,0.003908308195478309,0.00039878187655272967,-0.0035525515248662153,7.794918288060719e-05,7.967467881306615e-06,0.00031722542264225423,0.003554087104576814,-0.0006484139985020445,
         0.0,0.0,-0.0008106481624808136,-0.026040101599484264,0.0048695338480692196,-1.978581645224055e-05,-0.00011523602870610767,-0.0003926374669962829,5.115201532995485e-06,-0.00040831371686126576,0.03364077250817822,0.0009641179061576077,-0.0003604803147861901,-0.0027767673650206945,-0.000109729223305374,4.951552750211613e-06,5.877870001950215e-05,0.0011227376887696008,0.0005218810287212678,
         0.0,0.0,0.0102638602437232,0.01662678481030537,0.009182484039810914,0.00015429175705732696,0.0007716825318243701,-0.0022150489043572166,-1.555342382018241e-05,0.0032988274931616828,0.008203913166266579,0.002471677990529939,0.0016700680588649342,-0.04269618421822977,0.0007323822248014034,-1.5055828654067541e-05,7.169596691439751e-06,0.0041237857347445036,-0.007158319151278233,
         0.0,0.0,-0.027515124551571228,0.006100708865390153,0.0046824682645872535,-0.015195836037381755,0.0036610620363989746,-0.0026889489025574303,0.0002106839827484265,-0.020622118426419356,0.0019639820324520827,0.0014077690970109326,0.01029992124906957,-0.007816841601299253,-0.01045052282566221,0.00020394364347963294,0.03023122768852544,0.002904413557075258,0.02451762252719649,
         0.0,0.0,0.029598227826536476,-0.001947819310540344,-0.0016076879833772212,-0.015462541934207498,-0.004354678540079544,0.0014678399139666702,6.318506494863203e-05,-0.0073056970751906505,0.00023499796172121363,-0.0004990275847103182,-0.013609621389592062,0.008628353564627643,-0.019151681507527794,6.116360700106815e-05,0.03683033993205991,-0.0011110183124210392,-0.025876508867206754,
         0.0,0.0,-0.00309394593212548,-0.016410882304273566,-0.014819635118385362,-0.0024954268602339273,0.00025978892996935776,0.0650160369193193,-5.612585878226315e-05,0.00829521724747912,-0.01058865062074626,-0.004809491231367719,0.007464284482914694,-0.0167056058781731,-0.003966628493272947,-5.4330243303472635e-05,0.004895257043972488,-0.012094315081775766,0.0023332406141479555,
         0.0,0.0,0.015038508512109111,6.002574757499494e-05,5.545468668347562e-05,-0.007357228825100526,0.00021457666199436334,0.01233997171716356,0.00028815724590378723,-0.06615388613752146,1.5760963408139386e-05,1.821931710493762e-05,0.001503613676455512,-7.474350049319737e-05,0.034843699187346144,0.0002789383288375043,-0.01587592261934451,4.7562757587592584e-05,-0.008270629408188289,
         0.0,0.0,-0.015372363732540459,-0.00037391094074286553,-0.0003510063795583842,-0.05750610884073569,-0.0005751048344359273,-0.0020544813807548525,-0.00012862215487368238,0.02806979357474867,-0.0001989784185964058,-0.00011634984165108869,-0.016449701257641763,-0.0001057463159921084,0.050149032530810086,-0.0001245071897197403,0.007022078269523781,-0.00031244883164635064,-0.009607185864974858,
         0.0,0.0,0.04425709462146644,0.0017992528998897772,0.0017159250286645483,-0.004021265569142025,0.009560389379505813,0.005080383245438634,5.264377136173096e-05,0.0048920851646504235,0.0007375959055079597,0.0005739228864848861,-0.04198838799805905,-0.000710962195986285,0.005825347648367849,5.095955689457115e-05,0.000645680939580641,0.001587729653123099,0.06846319190919949,
         0.0,0.0,-0.03235895532704013,0.005391731429608386,0.0052157666332436885,0.017836072876812863,0.07020083194291006,0.01063354219533548,3.958435214064383e-05,-0.008826524044276255,0.0022550759941719727,0.0017590477238325073,-0.05803562522177466,-0.00188821251722764,-0.00661129953695208,3.8317943225557974e-05,-0.0006371738424064159,0.0050069871875634605,-0.023467655599731782,
         0.0,0.0,0.04120013022504826,-0.01776051986441235,-0.017640918003128926,-0.04033442692454259,0.09775424109537345,-0.02262269139868891,-0.00012164715478951157,0.00813723735153047,-0.008546120738938852,-0.006044909624356529,0.07163972926364821,0.0006201874180360446,-0.011896897335850719,-0.00011775533777569531,-0.014594018091864789,-0.0182287498444452,0.005011742358603745,
         0.0,0.0,0.013209484339468027,-0.06953214037089984,-0.07049534964495363,0.16771642925478103,0.03016836368509421,-0.06981710944675218,-7.535806441765804e-05,0.0181532560218304,-0.043884754298772456,-0.02446808608750978,0.0221427108011585,-0.047217384741993475,0.16625655743661236,-7.29471586985547e-05,0.16939016941651358,-0.07755427666702143,0.004399535819847487,
         0.0,0.0,-0.11348377734506669,-0.30985698925717353,-0.3152666000063226,-0.17708174049131784,-0.15025667576275173,-0.3002582074225296,-0.00022333336798364758,-0.1445535217194265,-0.21691394951335213,-0.1096732232790807,-0.26561966307258744,-0.31110866197032666,-0.23754236304398638,-0.00021618833703576317,-0.20722584030863614,-0.35080792006726713,1.974945156309565e-05,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
         0.0,0.0,1.6212030114752893e-14,1.8347500327427527e-21,1.2615299824713683e-21,1.2257280786963979e-14,2.5805579664798295e-15,4.0089961900898924e-22,2.0289385645107235e-06,2.0813534660096525e-13,1.4091659193544833e-15,3.3175880447328305e-22,5.739728844295354e-15,4.783726977508135e-15,8.750081765743302e-15,-2.0959527763604127e-06,-6.947476884065266e-14,-9.869693104920829e-14,-5.0688294905127385e-14,
         0.0,0.0,-4.994145878066802e-07,-4.59888052726537e-09,-6.130119910875888e-09,-3.780304549125529e-07,-7.901968882929053e-08,-1.3403041722360193e-09,-0.000649547833248007,-6.404706891376401e-06,-4.644834547667488e-08,-2.6599885039190887e-09,-1.760433677681509e-07,-1.4946976418410769e-07,-2.6966627279923486e-07,-0.0006287797440449831,2.1391637630320053e-06,3.0515315456268775e-06,1.5601859969964004e-06,
         0.0,0.0,-0.00014075516748384857,0.0026453960401476647,0.00391683233274255,3.379797974399629e-05,-6.156274482982617e-05,0.0006294259261501592,-2.3288465981648763e-05,9.885129845521813e-05,0.0018517940583946072,0.0019221123702859682,-2.2271593180281967e-05,0.0013753873591263233,-7.8131077501068e-06,-2.2543408918710526e-05,-0.0001308312083864741,-0.009247414851726409,6.105889991628549e-05,
         0.0,0.0,-8.855493784296467e-05,0.0014763523493257782,0.00404951213797264,1.54739007703806e-05,-2.7034378272617865e-05,0.00019927821771525015,-2.614430081814542e-06,1.7307686891732003e-05,0.0011134199966332165,-0.01667252155140309,-2.8140291723720513e-05,0.0005578428007995181,-4.693014593652951e-06,-2.530787619794265e-06,-4.966198590556816e-05,-0.0010055460269441142,4.6105513813501694e-05,
         0.0,0.0,0.000552990786974837,-0.009326426467294117,0.01482016585598855,-5.40533867615018e-05,0.00011903038908616345,-0.000528140956870046,4.11539630032416e-06,6.664709455348722e-05,-0.009611049371107797,0.0019541540977391545,0.00019939093827636483,-0.0017762757624331077,3.8974591440303596e-05,3.9837339406533076e-06,0.00015861271132112711,0.001777043552288407,-0.00032420699925102226,
         0.0,0.0,-0.0004053240812404068,-0.013020050799742132,0.0024347669240346098,-9.892908226120275e-06,-5.761801435305384e-05,-0.00019631873349814144,2.5576007664977423e-06,-0.00020415685843063288,0.01682038625408911,0.00048205895307880386,-0.00018024015739309505,-0.0013883836825103473,-5.4864611652687e-05,2.4757763751058063e-06,2.9389350009751074e-05,0.0005613688443848004,0.0002609405143606339,
         0.0,0.0,0.0051319301218616,0.008313392405152685,0.004591242019905457,7.714587852866348e-05,0.00038584126591218506,-0.0011075244521786083,-7.776711910091206e-06,0.0016494137465808414,0.004101956583133289,0.0012358389952649696,0.0008350340294324671,-0.021348092109114886,0.0003661911124007017,-7.527914327033771e-06,3.5847983457198753e-06,0.0020618928673722518,-0.0035791595756391164,
         0.0,0.0,-0.013757562275785614,0.0030503544326950763,0.0023412341322936268,-0.007597918018690877,0.0018305310181994873,-0.0013444744512787152,0.00010534199137421325,-0.010311059213209678,0.0009819910162260413,0.0007038845485054663,0.005149960624534785,-0.003908420800649627,-0.005225261412831105,0.00010197182173981647,0.01511561384426272,0.001452206778537629,0.012258811263598245,
         0.0,0.0,0.014799113913268238,-0.000973909655270172,-0.0008038439916886106,-0.007731270967103749,-0.002177339270039772,0.0007339199569833351,3.1592532474316015e-05,-0.0036528485375953252,0.00011749898086060681,-0.0002495137923551591,-0.006804810694796031,0.004314176782313822,-0.009575840753763897,3.058180350053408e-05,0.018415169966029956,-0.0005555091562105196,-0.012938254433603377,
         0.0,0.0,-0.00154697296606274,-0.008205441152136783,-0.007409817559192681,-0.0012477134301169637,0.00012989446498467888,0.03250801845965965,-2.8062929391131576e-05,0.00414760862373956,-0.00529432531037313,-0.0024047456156838596,0.003732142241457347,-0.00835280293908655,-0.0019833142466364733,-2.7165121651736317e-05,0.002447628521986244,-0.006047157540887883,0.0011666203070739777, 
         0.0,0.0,0.0075192542560545556,3.001287378749747e-05,2.772734334173781e-05,-0.003678614412550263,0.00010728833099718167,0.00616998585858178,0.00014407862295189361,-0.03307694306876073,7.880481704069693e-06,9.10965855246881e-06,0.000751806838227756,-3.7371750246598684e-05,0.017421849593673072,0.00013946916441875216,-0.007937961309672255,2.3781378793796292e-05,-0.004135314704094144,
         0.0,0.0,-0.007686181866270229,-0.00018695547037143276,-0.0001755031897791921,-0.028753054420367845,-0.00028755241721796363,-0.0010272406903774262,-6.431107743684119e-05,0.014034896787374336,-9.94892092982029e-05,-5.8174920825544344e-05,-0.008224850628820881,-5.28731579960542e-05,0.025074516265405043,-6.225359485987014e-05,0.0035110391347618905,-0.00015622441582317532,-0.004803592932487429,
         0.0,0.0,0.02212854731073322,0.0008996264499448886,0.0008579625143322741,-0.0020106327845710124,0.0047801946897529065,0.002540191622719317,2.632188568086548e-05,0.0024460425823252118,0.00036879795275397985,0.00028696144324244304,-0.020994193999029524,-0.0003554810979931425,0.0029126738241839244,2.5479778447285576e-05,0.0003228404697903205,0.0007938648265615495,0.03423159595459974,
         0.0,0.0,-0.016179477663520066,0.002695865714804193,0.0026078833166218443,0.008918036438406432,0.03510041597145503,0.00531677109766774,1.9792176070321916e-05,-0.0044132620221381275,0.0011275379970859863,0.0008795238619162536,-0.02901781261088733,-0.00094410625861382,-0.00330564976847604,1.9158971612778987e-05,-0.00031858692120320794,0.0025034935937817302,-0.011733827799865891,
         0.0,0.0,0.02060006511252413,-0.008880259932206175,-0.008820459001564463,-0.020167213462271294,0.048877120547686725,-0.011311345699344454,-6.0823577394755784e-05,0.004068618675765235,-0.004273060369469426,-0.0030224548121782647,0.03581986463182411,0.0003100937090180223,-0.005948448667925359,-5.8877668887847656e-05,-0.007297009045932394,-0.0091143749222226,0.0025058711793018726,
         0.0,0.0,0.0066047421697340136,-0.03476607018544992,-0.035247674822476815,0.08385821462739051,0.015084181842547105,-0.03490855472337609,-3.767903220882902e-05,0.0090766280109152,-0.021942377149386228,-0.01223404304375489,0.01107135540057925,-0.023608692370996737,0.08312827871830618,-3.647357934927735e-05,0.08469508470825679,-0.038777138333510715,0.0021997679099237436,
         0.0,0.0,-0.056741888672533346,-0.15492849462858677,-0.1576333000031613,-0.08854087024565892,-0.07512833788137586,-0.1501291037112648,-0.00011166668399182379,-0.07227676085971325,-0.10845697475667607,-0.05483661163954035,-0.13280983153629372,-0.15555433098516333,-0.11877118152199319,-0.00010809416851788159,-0.10361292015431807,-0.17540396003363357,9.874725781547824e-06;
    return M;
}
