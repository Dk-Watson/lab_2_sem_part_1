using Microsoft.VisualStudio.TestTools.UnitTesting;
using _2._4_1._10Models;

namespace UnitTestProject1
{
    [TestClass]
    public class YearCalcTEST
    {
        [TestMethod]
        public void YearCalc_2024and2000_24returned()
        {
            nasled_lab a = new nasled_lab
            {
                Well = 2000 // Подставьте правильное значение для well
            };
            int result = a.YearCalc();
            Assert.AreEqual(24, result); // Подставьте правильное ожидаемое значение
        }
    }
}