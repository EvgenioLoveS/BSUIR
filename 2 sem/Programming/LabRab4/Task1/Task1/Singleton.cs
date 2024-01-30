    using System.ComponentModel.Design.Serialization;

    namespace Task1
    {
        public class ATCTariffContainer // класс-контейнер
        {
            private static ATCTariffContainer instance;
            private  string address;
            private  int numberOfSubscribers;
            private  double subscriptionFee;

            private ATCTariffContainer()
            {
            }

            public static ATCTariffContainer GetInstance()
            {
                if (instance == null)
                {
                    instance = new ATCTariffContainer();
                }

                return instance;
            }

            public string Address
            {
                get { return address; }
                set { address = value; }
            }

            public int NumberOfSubscribers
            {
                get { return numberOfSubscribers; }
                set { numberOfSubscribers = value; }
            }

            public double SubscriptionFee
            {
                get { return subscriptionFee; }
                set { subscriptionFee = value; }
            }

            public double GetTotalSubscriptionFee()
            {
                return subscriptionFee * numberOfSubscribers;
            }

            public void IncreaseTariff(double amount)
            {
                subscriptionFee += amount;
            }

            public void DecreaseTariff(double amount)
            {
                subscriptionFee -= amount;
            }
        }
    }