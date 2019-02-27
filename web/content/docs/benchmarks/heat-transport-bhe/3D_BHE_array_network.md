---
author:
- 'Shuang Chen, Francesco Witte and Haibing Shao'
bibliography:
- '3D\_BHE\_array\_network\_references.bib'
title: |
    A 3D benchmark of modeling the ground temperature variation due to the
    operation of a Borehole Heat Exchangers (BHEs) array
---

BHE array network,BHE thermal exchange rate shifting,OGS ,TESPy ,EPANET

Background and Motivation {#sec1}
=========================

Utilizing shallow geothermal energy for heating and cooling buildings
has received increasing interest in recent years. For large commercial
buildings or energy storage applications,a typical system will include
hundreds of Borehole Heat Exchangers (BHEs) that were connected with
each other through a pipe network laid on top of them. Depending on the
different arrangements of BHEs (connected in a serial or parallel way),
the heat exchange rate of BHEs may vary.

In order to simulate the dynamics soil and BHE temperature evolution in
response to the shallow geothermal energy extraction or storage process,
the conventional analytical approach will impose a heat extraction rate
on each BHE as a Neumann type of boundary condition, and the temperature
distribution of the subsurface is then calculated by super-imposing the
individual temperature change induced by each BHE. This approach is not
capable of predicting the interaction and influence from the pipe
network, which the performance of each BHE is heavily dependent on. In
this benchmark numerical model has been constructed to explicitly
simulate a a 3-BHE system coupled with pipe network. The model is based
on two open-source software, OGS and the Thermal Engineering Systems in
Python (TESPy). These two software are linked together through a
C++/Python interface. The coupled model allows a dynamic heat extraction
rate of each BHE that is determined by the flow and heat transport
processes in the pipe network. The simulation results of the soil
temperature distribution in vicinity of the BHE have been compared with
the super-imposition analytical approach. For the details on the
analytical solution for a BHE array, please refer to the benchmark of
BHE Array 2D in the section \"Heat conduction\". Besides, investigations
have been focusing on the variation of the inflow, outflow temperature
and the dynamic thermal exchange rate on each BHE. In the presented
result, it can be found that the temporal variation of the thermal
exchange rate is determined by the interaction between subsurface, BHEs,
and the pipe network.

Model setup {#sec2}
===========

The model used in this benchmark is composed of two parts. The pipe
network is simulated by TESPy, while the temperature distribution in
soil and BHE is simulated by OGS. The modelling domain and finite
element mesh used in OGS is illustrated in
Figure [\[AB\_Sec2\_1\]](#AB_Sec2_1){reference-type="ref"
reference="AB_Sec2_1"}. The model has a geometry of 60 m $\times$ 30 m
$\times$ 30 m. The z-direction is composed of 6 layers. The 3 BHEs are
simulated by three line elements that are located in the center part of
the model. In this benchmark, the 1U pipe type BHE is adopted
 [@Diersch]. The inflow temperature and outflow temperatures are the
primary variables on the line elements. The model parameters are listed
in the following Table
[\[TA\_Sec2\_1\]](#TA_Sec2_1){reference-type="ref"
reference="TA_Sec2_1"}

  Parameter                                         Symbol         Value                Unit
  ------------------------------------------------- -------------- -------------------- ------------------
  Soil thermal conductivity                         $\lambda_s$    2.78018              $Wm^{-1}K^{-1}$
  Soil heat capacity                                $(\rho c)_s$   $1.43\times10^{6}$   $J^{-3} mK^{-1}$
  Initial subsurface temperature                    $T_0$          295.25               $K$
  Heat extraction rate of the BHE for analytical    $q$            30                   $W/m$
  Length of the BHE                                 $L$            50                   $m$
  Diameter of the BHE                               $D$            0.13                 $m$
  Diameter of the inflow and outflow pipe           $d_0$          0.013665             $m$
  Wall thickness of pipe                            $b_0$          0.003035             $m$
  Wall thermal conductivity                         $\lambda_0$    0.39                 $Wm^{-1}K^{-1}$
  Grout thermal conductivity                        $\lambda_g$    0.806                $Wm^{-1}K^{-1}$
  Grout heat capacity                               $(\rho c)_g$   $3.8\times10^{6}$    $J^{-3} mK^{-1}$
  Refrigerant thermal conductivity                  $\lambda_f$    0.62863              $Wm^{-1}K^{-1}$
  Refrigerant heat capacity                         $(\rho c)_f$   $4.16\times10^{6}$   $J^{-3} mK^{-1}$
  Refrigerant viscosity                             $visc$         0.00067418           $-$
  [\[TA\_Sec2\_1\]]{#TA_Sec2_1 label="TA_Sec2_1"}                                       

![Model of the 3 BHEs array network in
OGS](3D_3BHE_array_network_figures/3bhe_model){width="60%"}

[\[AB\_Sec2\_1\]]{#AB_Sec2_1 label="AB_Sec2_1"}

The pipeline network model is constructed based on the software TESPy,
and its components are illustrated as in
Figure [\[AB\_Sec2\_2\]](#AB_Sec2_2){reference-type="ref"
reference="AB_Sec2_2"}. In the pipe network, the heat transport is
controlled by pipe flow. At the entry point of this network, the
pressure of inflow water is raised by a pump. Due to the pipeline
network connectivity, the flow is firstly divided into 3 branches and
then joined at the merging point. After mixing, the total extracted heat
is consumed by an end-user, presumably some radiators in the building.
As the energy consumed equals to the energy extracted from BHEs plus the
waste heat from the pump, the pipeline network reaches both thermal and
hydraulic steady-state. A constant thermal consumer by end-user with
4500 W was imposed as the boundary condition for the system. The total
modelling time is 90 days, representing a typical heating season.

For the construction of a pipe network in TESPy, detailed tutorials can
be found in the TESPy online documentation site [@Witte]. The
verification of TESPy in terms of its hydraulic state calculation and
heat transport part can be found in the attached PDF document \[this
PDF\](../Tespy_3BHE_Benchmark.pdf). In this benchmark the adopted
TESPy version is V0.0.5.

![Topology of 3 BHEs array network in
TESPy](3D_3BHE_array_network_figures/BHE_network){width="60%"}

[\[AB\_Sec2\_2\]]{#AB_Sec2_2 label="AB_Sec2_2"}

Results {#sec3}
=======

Figure [\[AB\_Sec3\_1\]](#AB_Sec3_1){reference-type="ref"
reference="AB_Sec3_1"} depicts the comparison of computed temperature
distribution in soil after 90 days simulated by OGS-TESPy, compared
against the analytical solution result. Please notice that these two
curves are supposed to be similar but not exactly the same. The
analytical solution assumes the identical heat extraction rate (1500W)
on each BHE, while the numerical OGS-TESPy model only impose a total
4500 W heat extraction on the entire system. The actual extraction rate
in the OGS-TESPy model is determined dynamically by the actual flow and
heat transport process in the pipe network. The variation of the inflow
and outflow temperature on each BHE is illustrated in
Figure [\[AB\_Sec3\_2\]](#AB_Sec3_2){reference-type="ref"
reference="AB_Sec3_2"}. The inflow temperature in all 3 BHEs remains
identical over the operation time since they have a common source flow
from the system inlet. However the outflow temperature from the BHE in
the middle (BHE2) is slightly lower than the outflow temperature from
BHE1 and BHE3, which are located on the two sides. As shown in the
Figure  [\[AB\_Sec3\_3\]](#AB_Sec3_3){reference-type="ref"
reference="AB_Sec3_3"} the thermal exchange rate in the BHE2 decreases
gradually over the time, while the rates in BHE1 and BHE3 are
increasing. At the end of the 90-day heating period, the heat extraction
rate on BHE2 will be about 30 W (2%) lower than the initial value, while
the rates on BHE1 and BHE3 will be 12 W (1%) higher. The difference in
heat exchange rates is caused by the different soil temperature
distribution in vicinity of each BHE. The soil temperature in the center
of the model domain is lower than those on the outskirt. This means, the
center part of the subsurface is more susceptible to coldness
accumulated over the heating period. In the analytical solution, this
phenomenon can not be captured since fixed heat extraction rate boundary
condition has to be imposed on each BHE.

![Comparison with analytical solution against OGS results for soil
temperature distribution after 90
days](3D_3BHE_array_network_figures/soil_temp.png){width="80%"}

[\[AB\_Sec3\_1\]]{#AB_Sec3_1 label="AB_Sec3_1"}

![Inflow temperature and outflow temperature within the BHE in 90
day](3D_3BHE_array_network_figures/with_network_bhe_T.png){width="80%"}

[\[AB\_Sec3\_2\]]{#AB_Sec3_2 label="AB_Sec3_2"}

![Comparison the thermal exchange rate for each BHE from OGS against
analytical
solution](3D_3BHE_array_network_figures/bhe_power.png){width="80%"}

[\[AB\_Sec3\_3\]]{#AB_Sec3_3 label="AB_Sec3_3"}

Summary and Discussions
=======================

In this benchmark, a 3-BHE model connected with pipe network is
constructed in order to simulate the subsurface temperature evolution
and predict the actual dynamic performance of the thermal exchange rate
on each BHE. The modeling results showed that after 90 days' operation,
the BHE in the center of the array was experiencing a lower heat
extraction rate. Through the long-term operation, the thermal load was
gradually shifted towards those BHEs located at the outskirt boundary of
the array. In the current benchmark, the max deveation of heat
extraction rate is only about 2% (from 1500 W to 1470 W). However, for
large Ground Source Heat Pump systems where hundres of BHEs are
employed, cold accumulation is more likely to occur, leading to a
stronger interaction between BHEs and the pipe network.